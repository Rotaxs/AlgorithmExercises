import importlib.util
import json
import unittest
from pathlib import Path
from unittest.mock import patch

spec = importlib.util.spec_from_file_location(
    "oj_stats", Path(__file__).resolve().parents[1] / "scripts/update_oj_stats.py"
)
stats = importlib.util.module_from_spec(spec)
spec.loader.exec_module(stats)


class StatsTests(unittest.TestCase):
    def test_public_page_counts(self):
        payload = {"template": "user.show", "data": {"user": {
            "uid": 1817237, "passedProblemCount": 339, "submittedProblemCount": 344}}}
        body = '<script type="application/json">' + json.dumps(payload) + '</script>'
        self.assertEqual(stats.parse_luogu(body, "1817237"), 339)
        with self.assertRaises(ValueError):
            stats.parse_luogu(body, "123")

    def test_leetcode_counts_and_errors(self):
        def response(items):
            return {"data": {"userProfileUserQuestionProgress": {"numAcceptedQuestions": items}}}
        items = [{"difficulty": level, "count": count} for level, count in
                 zip(("EASY", "MEDIUM", "HARD"), (0, 7, 2))]
        self.assertEqual(stats.parse_leetcode(response(items)), 9)
        with self.assertRaises(ValueError):
            stats.parse_leetcode(response(items[:2]))
        with self.assertRaises(ValueError):
            stats.parse_leetcode({"errors": [{"message": "not found"}]})
        for value in (-1, True, "9", None):
            with self.assertRaises(ValueError):
                stats.count_value(value)

    def test_codeforces_pagination_and_deduplication(self):
        accepted = {"verdict": "OK", "problem": {"contestId": 2258, "index": "C"}}
        wrong = {"verdict": "WRONG_ANSWER", "problem": {"contestId": 2258, "index": "D"}}
        class Client:
            def __init__(self):
                self.urls = []

            def json(self, url):
                self.urls.append(url)
                if len(self.urls) == 1:
                    return {"status": "OK", "result": [accepted] * 999 + [wrong]}
                return {"status": "OK", "result": [accepted, {
                    "verdict": "OK", "problem": {"contestId": 2258, "index": "D"}}]}
        client = Client()
        with patch.object(stats.time, "sleep"):
            self.assertEqual(stats.fetch_codeforces(client, "rotaxis"), 2)
        self.assertIn("from=1001", client.urls[1])

    def test_failure_preserves_only_same_account_history(self):
        accounts = {platform: "user" for platform in stats.PLATFORMS}
        previous = {platform: {"account": "user", "count": 10,
                               "updated_at": "2026-01-01 00:00:00"} for platform in stats.PLATFORMS}
        previous["luogu"]["account"] = "another-user"
        previous["nowcoder"]["count_scope"] = "acm-main-personal-v1"
        with patch.object(stats, "fetch_count", side_effect=TimeoutError("timeout")):
            results = stats.collect(accounts, previous, None, "now")
        self.assertIsNone(results["luogu"]["count"])
        self.assertEqual(results["luogu"]["status"], "unavailable")
        self.assertEqual(results["codeforces"]["count"], 10)
        self.assertEqual(results["codeforces"]["updated_at"], "2026-01-01 00:00:00")
        self.assertEqual(results["codeforces"]["status"], "stale")
        self.assertIn("40（不完整", stats.render(results))
        with patch.object(stats, "fetch_count", return_value=0):
            results = stats.collect(accounts, previous, None, "now")
        self.assertTrue(all(entry["status"] == "ok" for entry in results.values()))
        self.assertIn("总通过题数：0**", stats.render(results))

    def test_readme_preservation_and_deterministic_rendering(self):
        results = {platform: {"account": "user", "count": 1, "updated_at": "now", "status": "ok"}
                   for platform in stats.PLATFORMS}
        original = '# Intro\n' + stats.START + '\nold\n' + stats.END + '\n## Notes\n'
        block = stats.render(results)
        updated = stats.replace_block(original, block)
        self.assertTrue(updated.startswith('# Intro\n'))
        self.assertTrue(updated.endswith('\n## Notes\n'))
        self.assertEqual(stats.replace_block(updated, stats.render(results)), updated)
        self.assertIn("总通过题数：5", updated)
        for bad in ('no markers', stats.END + stats.START, original + stats.START):
            with self.assertRaises(ValueError):
                stats.replace_block(bad, block)

    def test_http_retries(self):
        client = stats.PublicClient()
        with patch.object(client.opener, "open", side_effect=stats.urllib.error.URLError("offline")) as request:
            with patch.object(stats.time, "sleep"):
                with self.assertRaises(stats.urllib.error.URLError):
                    client.request("https://example.com")
        self.assertEqual(request.call_count, 3)

    def test_nowcoder_acm_rows_include_contest_and_reject_missing_ids(self):
        parser = stats.NowcoderACMParser()
        parser.feed('''<table><tr><td>运行ID</td></tr>
            <tr><td><a href="/acm/contest/view-submission?submissionId=1">1</a></td>
            <td><a href="/acm/problem/20">contest problem</a></td><td>答案正确</td></tr>
            <tr><td><a href="/acm/contest/view-submission?submissionId=2">2</a></td>
            <td><a href="/acm/problem/21">wrong answer</a></td><td>答案错误</td></tr></table>''')
        self.assertEqual(len(parser.rows), 2)
        self.assertEqual(parser.rows[0]["problem_id"], "20")
        self.assertIn("答案正确", parser.rows[0]["text"])
        with self.assertRaises(ValueError):
            stats.NowcoderACMParser().feed('<tr><a href="?submissionId=1">1</a></tr>')

    def test_nowcoder_main_pagination_deduplicates_tracker_and_practice(self):
        def record(submission, problem, accepted=True):
            return {"submission": {"id": submission}, "problem": {"id": problem}, "accept": accepted}
        class Client:
            def __init__(self):
                self.calls = []

            def json(self, url, payload):
                self.calls.append(payload)
                page = payload["pageNo"]
                records = ([record(1, 20), record(2, 20), record(3, 21, False)] if page == 1
                           else [record(4, 22)])
                return {"code": 0, "data": {"current": page, "total": 4, "totalPage": 999, "records": records}}
        client = Client()
        with patch.object(stats.time, "sleep"):
            self.assertEqual(stats.fetch_nowcoder_main(client, "439254888"), {"20", "22"})
        self.assertEqual([x["pageNo"] for x in client.calls], [1, 2])
        with patch.object(stats, "fetch_nowcoder_acm", return_value={"20", "30"}):
            with patch.object(stats, "fetch_nowcoder_main", return_value={"20", "22"}):
                with patch.object(stats, "fetch_nowcoder_team", return_value={"30", "40"}) as team:
                    self.assertEqual(stats.fetch_nowcoder(None, "439254888"), 3)
                    team.assert_not_called()
                    self.assertEqual(stats.fetch_nowcoder(None, "439254888", True), 4)

    def test_nowcoder_incomplete_history_is_failure(self):
        class Client:
            def json(self, url, payload):
                return {"code": 0, "data": {"current": payload["pageNo"], "total": 5, "records": []}}
        with self.assertRaises(ValueError):
            stats.fetch_nowcoder_main(Client(), "439254888")
        with self.assertRaises(ValueError):
            stats.nowcoder_data({"code": 1, "data": {}})

    def test_nowcoder_acm_pagination_and_summary_validation(self):
        def page(rows):
            return ('<script>window.curUser.id = "439254888";</script>'
                    '<div>3</div><span>次提交</span><div>2</div><span>题已通过</span>'
                    + ''.join(f'<tr><a href="?submissionId={submission}">{submission}</a>'
                              f'<a href="/acm/problem/{problem}">题目</a><td>答案正确</td></tr>'
                              for submission, problem in rows))
        client = unittest.mock.Mock()
        client.request.side_effect = [page([(1, 20), (2, 20)]), page([(3, 21)])]
        with patch.object(stats.time, "sleep"):
            self.assertEqual(stats.fetch_nowcoder_acm(client, "439254888"), {"20", "21"})
        self.assertIn("page=2", client.request.call_args.args[0])
        client.request.side_effect = [page([(1, 20)]), page([])]
        with patch.object(stats.time, "sleep"), self.assertRaises(ValueError):
            stats.fetch_nowcoder_acm(client, "439254888")
        client.request.side_effect = ['<p>请登录</p>']
        with self.assertRaises(ValueError):
            stats.fetch_nowcoder_acm(client, "439254888")

    def test_old_nowcoder_scope_not_reported_as_full_total(self):
        accounts = {platform: "user" for platform in stats.PLATFORMS}
        old = {"nowcoder": {"account": "user", "count": 19, "updated_at": "old", "status": "ok"}}
        with patch.object(stats, "fetch_count", side_effect=TimeoutError("offline")):
            results = stats.collect(accounts, old, None, "now")
        self.assertIsNone(results["nowcoder"]["count"])
        self.assertEqual(results["nowcoder"]["status"], "unavailable")

    def test_nowcoder_team_records_validate_account_and_deduplicate(self):
        class Client:
            def json(self, url):
                if "contest-joined-history" in url:
                    return {"code": 0, "data": {"dataList": [
                        {"isTeamSignUp": True, "contestId": 100, "teamId": 200},
                        {"isTeamSignUp": False, "contestId": 101}], "pageInfo": {"pageCount": 1}}}
                return {"code": 0, "data": {"basicInfo": {"contestId": 100, "searchUserName": "200", "pageCount": 1, "pageCurrent": 1, "statusCount": 2},
                    "data": [{"userId": 200, "isTeam": True, "submissionId": 1, "statusMessage": "答案正确", "problemId": 20},
                             {"userId": 200, "isTeam": True, "submissionId": 2, "statusMessage": "答案正确", "problemId": 20}]}}
        with patch.object(stats.time, "sleep"):
            self.assertEqual(stats.fetch_nowcoder_team(Client(), "439254888"), {"20"})


if __name__ == "__main__":
    unittest.main()
