#!/usr/bin/env python3
"""Fetch public OJ accepted counts and replace only the README stats block."""

import argparse
import http.client
import http.cookiejar
import json
import re
import sys
import time
import urllib.error
import urllib.parse
import urllib.request
from datetime import datetime, timezone, timedelta
from html.parser import HTMLParser
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
START = "<!-- OJ-STATS:START -->"
END = "<!-- OJ-STATS:END -->"
PLATFORMS = {
    "luogu": ("洛谷", "https://www.luogu.com.cn/user/{}"),
    "nowcoder": ("牛客 ACM（练习）", "https://ac.nowcoder.com/acm/contest/profile/{}/practice-coding"),
    "leetcode": ("力扣中国站", "https://leetcode.cn/u/{}/"),
    "codeforces": ("Codeforces", "https://codeforces.com/profile/{}"),
    "atcoder": ("AtCoder", "https://atcoder.jp/users/{}"),
}


def count_value(value):
    if type(value) is not int or value < 0:
        raise ValueError("通过题数不是非负整数")
    return value


class PublicClient:
    def __init__(self):
        # Luogu sets public visitor cookies before redirecting to the same URL.
        self.opener = urllib.request.build_opener(
            urllib.request.HTTPCookieProcessor(http.cookiejar.CookieJar())
        )

    def request(self, url, payload=None):
        data = json.dumps(payload).encode() if payload is not None else None
        headers = {"User-Agent": "Mozilla/5.0 (compatible; OJStats/1.0)", "Referer": url}
        if data is not None:
            headers["Content-Type"] = "application/json"
        for attempt in range(3):
            try:
                request = urllib.request.Request(url, data=data, headers=headers)
                with self.opener.open(request, timeout=25) as response:
                    return response.read().decode("utf-8")
            except urllib.error.HTTPError as error:
                if error.code not in (408, 429, 500, 502, 503, 504) or attempt == 2:
                    raise
            except (OSError, http.client.HTTPException):
                if attempt == 2:
                    raise
            time.sleep(2 ** (attempt + 1))

    def json(self, url, payload=None):
        return json.loads(self.request(url, payload))


class PageParser(HTMLParser):
    """Extract visible text and JSON script bodies without a third-party parser."""

    def __init__(self):
        super().__init__()
        self.text = []
        self.json_scripts = []
        self.script = None
        self.hidden = False

    def handle_starttag(self, tag, attrs):
        if tag in ("script", "style"):
            self.hidden = True
        if tag == "script" and dict(attrs).get("type") == "application/json":
            self.script = []

    def handle_endtag(self, tag):
        if tag == "script" and self.script is not None:
            self.json_scripts.append("".join(self.script))
            self.script = None
        if tag in ("script", "style"):
            self.hidden = False

    def handle_data(self, data):
        if self.script is not None:
            self.script.append(data)
        elif not self.hidden and data.strip():
            self.text.append(data.strip())


def parse_luogu(body, account):
    parser = PageParser()
    parser.feed(body)
    for raw in parser.json_scripts:
        data = json.loads(raw)
        if data.get("template") == "user.show":
            user = data["data"]["user"]
            if str(user["uid"]) != account:
                raise ValueError("洛谷返回的账号不匹配")
            return count_value(user["passedProblemCount"])
    raise ValueError("洛谷主页未包含公开通过题数")


def parse_nowcoder(body):
    parser = PageParser()
    parser.feed(body)
    match = re.search(r"(?:^|\s)(\d+)\s+题已通过(?:\s|$)", " ".join(parser.text))
    if not match:
        raise ValueError("牛客练习页未包含公开通过题数")
    return count_value(int(match.group(1)))


def parse_leetcode(data):
    if data.get("errors"):
        raise ValueError("力扣 GraphQL 返回错误")
    values = data["data"]["userProfileUserQuestionProgress"]["numAcceptedQuestions"]
    if not isinstance(values, list) or len(values) != 3:
        raise ValueError("力扣通过数数据不完整")
    if {item["difficulty"] for item in values} != {"EASY", "MEDIUM", "HARD"}:
        raise ValueError("力扣难度分类不完整")
    return sum(count_value(item["count"]) for item in values)


def fetch_codeforces(client, account):
    solved = set()
    offset, page_size = 1, 1000
    while True:
        query = urllib.parse.urlencode({"handle": account, "from": offset, "count": page_size})
        data = client.json("https://codeforces.com/api/user.status?" + query)
        if data.get("status") != "OK" or not isinstance(data.get("result"), list):
            raise ValueError("Codeforces API 返回错误")
        records = data["result"]
        for record in records:
            if record.get("verdict") == "OK":
                problem = record["problem"]
                # Gym problems also have contestId; problemsetName covers other sets.
                contest = problem.get("contestId")
                if contest is None:
                    contest = problem.get("problemsetName")
                if contest is None or not problem.get("index"):
                    raise ValueError("Codeforces 通过记录缺少题目标识")
                solved.add((contest, problem["index"]))
        if len(records) < page_size:
            return len(solved)
        offset += page_size
        time.sleep(2.2)


def fetch_count(client, platform, account):
    encoded = urllib.parse.quote(account, safe="")
    if platform == "luogu":
        return parse_luogu(client.request(PLATFORMS[platform][1].format(encoded)), account)
    if platform == "nowcoder":
        return parse_nowcoder(client.request(PLATFORMS[platform][1].format(encoded)))
    if platform == "leetcode":
        payload = {
            "query": "query($userSlug: String!) { userProfileUserQuestionProgress(userSlug: $userSlug) { numAcceptedQuestions { difficulty count } } }",
            "variables": {"userSlug": account},
        }
        return parse_leetcode(client.json("https://leetcode.cn/graphql/", payload))
    if platform == "codeforces":
        return fetch_codeforces(client, account)
    if platform == "atcoder":
        return count_value(client.json(
            "https://kenkoooo.com/atcoder/atcoder-api/v3/user/ac_rank?user=" + encoded
        )["count"])
    raise ValueError("未知平台")


def collect(accounts, previous, client, now):
    results = {}
    for platform in PLATFORMS:
        account = accounts[platform]
        old = previous.get(platform, {})
        entry = {"account": account, "count": None, "updated_at": None, "status": "unavailable"}
        # Never carry another account's count over after a config change.
        if old.get("account") == account:
            entry.update({key: old.get(key) for key in ("count", "updated_at")})
        try:
            entry.update(count=count_value(fetch_count(client, platform, account)),
                         updated_at=now, status="ok")
            print(f"{platform}: {entry['count']}")
        except (ValueError, KeyError, TypeError, OSError, http.client.HTTPException) as error:
            entry["status"] = "stale" if entry["count"] is not None else "unavailable"
            # Do not publish response bodies or transient errors in the README/cache.
            print(f"WARNING {platform}: {type(error).__name__}: {error}", file=sys.stderr)
        results[platform] = entry
    return results


def render(results):
    lines = [START, "## 刷题统计", "", "| 平台 | 账号 | 通过题数 | 上次成功更新（北京时间） | 状态 |",
             "| --- | --- | ---: | --- | --- |"]
    statuses = {"ok": "正常", "stale": "获取失败，保留历史数据", "unavailable": "暂不可用"}
    for platform, (name, url) in PLATFORMS.items():
        entry = results[platform]
        account = entry["account"]
        count = entry["count"] if entry["count"] is not None else "—"
        updated = entry["updated_at"] or "—"
        link = url.format(urllib.parse.quote(account, safe=""))
        lines.append(f"| {name} | [{account}]({link}) | {count} | {updated} | {statuses[entry['status']]} |")
    total = sum(entry["count"] for entry in results.values() if entry["count"] is not None)
    incomplete = any(entry["count"] is None for entry in results.values())
    stale = any(entry["status"] == "stale" for entry in results.values())
    qualifier = "（不完整，仅汇总已有数据）" if incomplete else "（含历史数据）" if stale else ""
    lines += ["", f"**总通过题数：{total}{qualifier}**", "",
              "统计口径：平台内按题目去重，总数为各平台通过题数之和，跨平台同题重复计数。",
              "牛客采用 ACM 练习页的“题已通过”，不包含比赛题；AtCoder 使用第三方 AtCoder Problems 的统计，可能有同步延迟。",
              "每天北京时间 08:17 左右自动更新，也可在 GitHub Actions 中手动刷新。", END]
    return "\n".join(lines)


def replace_block(readme, block):
    if readme.count(START) != 1 or readme.count(END) != 1:
        raise ValueError("README 必须包含唯一的 OJ-STATS 开始和结束标记")
    start, end = readme.index(START), readme.index(END)
    if end < start:
        raise ValueError("README 统计标记顺序错误")
    return readme[:start] + block + readme[end + len(END):]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--dry-run", action="store_true", help="查询并展示统计，不写入文件")
    args = parser.parse_args()
    accounts = json.loads((ROOT / "scripts/oj_accounts.json").read_text())
    for platform in PLATFORMS:
        if not isinstance(accounts.get(platform), str) or not re.fullmatch(r"[A-Za-z0-9_-]+", accounts[platform]):
            raise ValueError(f"{platform} 账号配置无效")
    path = ROOT / "data/oj_stats.json"
    previous = json.loads(path.read_text()) if path.exists() else {}
    readme_path = ROOT / "README.md"
    readme = readme_path.read_text()
    # Check markers before spending time on network requests or writing cache.
    replace_block(readme, START + "\n" + END)
    now = datetime.now(timezone(timedelta(hours=8))).strftime("%Y-%m-%d %H:%M:%S")
    results = collect(accounts, previous, PublicClient(), now)
    block = render(results)
    if args.dry_run:
        print(block)
        return
    updated = replace_block(readme, block)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(results, ensure_ascii=False, indent=2) + "\n")
    readme_path.write_text(updated)


if __name__ == "__main__":
    main()
