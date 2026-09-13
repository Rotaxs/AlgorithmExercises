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
        body = '<div>50</div><span>次提交</span><div>19</div><span>题已通过</span>'
        self.assertEqual(stats.parse_nowcoder(body), 19)
        self.assertEqual(stats.parse_nowcoder('<div>0</div><span>题已通过</span>'), 0)
        with self.assertRaises(ValueError):
            stats.parse_nowcoder('<script>19 题已通过</script><p>请登录</p>')

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


if __name__ == "__main__":
    unittest.main()
