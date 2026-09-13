# Algorithm Exercises

算法竞赛 / 刷题练习仓库，收录比赛题解、平台练习与个人整理的算法模板笔记。

<!-- OJ-STATS:START -->
## 刷题统计

| 平台 | 账号 | 通过题数 | 上次成功更新（北京时间） | 状态 |
| --- | --- | ---: | --- | --- |
| 洛谷 | [1817237](https://www.luogu.com.cn/user/1817237) | 339 | 2026-09-13 11:37:30 | 正常 |
| 牛客（练习 / 比赛 / tracker） | [439254888](https://ac.nowcoder.com/acm/contest/profile/439254888) | 129 | 2026-09-13 11:37:30 | 正常 |
| 力扣中国站 | [rotaxis](https://leetcode.cn/u/rotaxis/) | 9 | 2026-09-13 11:37:30 | 正常 |
| Codeforces | [rotaxis](https://codeforces.com/profile/rotaxis) | 86 | 2026-09-13 11:37:30 | 正常 |
| AtCoder | [rotas](https://atcoder.jp/users/rotas) | 40 | 2026-09-13 11:37:30 | 正常 |

**总通过题数：603**

统计口径：平台内按题目去重，总数为各平台通过题数之和，跨平台同题重复计数。
牛客合并 ACM 个人提交（含个人比赛）与主站提交（含 tracker / 每日一题），按统一 problemId 去重；团队赛包含自己参赛队伍的通过题目。
AtCoder 使用第三方 AtCoder Problems 的统计，可能有同步延迟。
每天北京时间 08:17 左右自动更新，也可在 GitHub Actions 中手动刷新。
<!-- OJ-STATS:END -->

## 目录结构

```
.
├── Contests/               # 各种比赛
│   ├── ABC457/             # AtCoder Beginner Contest，题目文件为 A.cpp ~ Z.cpp
│   ├── CF_Round_1098_div2/ # Codeforces
│   ├── Nowcoder_Weekly154/ # 牛客周赛
│   ├── ICPC_.../  CCPC_.../  CSP*/  CQUT*/  ...
├── Exercises/              # 平台刷题练习
│   ├── Luogu/              # 洛谷，p/b + 题号，如 p1002.cpp
│   ├── Nowcoder/           # 牛客，nc/bgn + 题号，tracker_daily_ 为每日一题
│   ├── LeetCode/           # lc + 题号_题名
│   ├── Astar/  Codeforces/ Other/  # 百度之星 / CF 题单 / 其他 OJ
├── algorithm/              # 算法模板与学习代码
│   ├── number_theory/      # 数论
│   ├── graph/              # 图论
│   ├── structure/          # 数据结构
│   ├── templates/          # 模板笔记
│   └── ...                 # sort / search / dp / 双指针 / 前缀和 / 状态机
├── template.cpp            # 提交模板
└── README.md
```

## 约定

- 语言以 C++17 为主，单文件提交，使用 `template.cpp` 作为起点（含 `ONLINE_JUDGE` 调试开关）。
- `algorithm/templates/` 收录两类笔记：`algorithm_templates.md`（算法原理 + 推导）与 `ready_made_templates.md`（可直接复制的封装模板）。

## 自动更新刷题统计

- 账号配置在 `scripts/oj_accounts.json`，仅需公开用户名或 UID，无需密码、登录 Cookie 或 GitHub PAT。
- 牛客合并 ACM 个人通过记录（含个人比赛）、主站通过记录（含 tracker / 每日一题）以及本人参赛队伍的通过记录，按统一 `problemId` 去重。当前 `nowcoder_include_team` 为 `true`，设为 `false` 可关闭团队赛统计；团队公开记录不能区分具体提交成员。
- 使用 Python 3.12（无第三方依赖）运行 `python3 scripts/update_oj_stats.py`，更新 README 和 `data/oj_stats.json`；加 `--dry-run` 可只查看结果。
- 将配置推送到 GitHub 默认分支后，工作流每天北京时间 08:17 左右执行（GitHub 调度可能延迟）。也可在 **Actions → Update OJ stats → Run workflow** 手动刷新。
- 工作流使用自带的 `GITHUB_TOKEN` 提交更新，需要仓库允许 Actions 的 `contents: write` 权限，且默认分支允许机器人直接提交；若仓库策略禁止，会在 Actions 日志中显示推送失败。
- 远程统计更新后，本地通过 `git pull --rebase` 获取。公开仓库的定时工作流在连续 60 天无仓库活动时可能被 GitHub 停用，可在 Actions 中重新启用（[GitHub 调度说明](https://docs.github.com/en/actions/reference/workflows-and-actions/events-that-trigger-workflows#schedule)）。
- 获取失败时保留该账号上次成功数据；首次获取失败显示“暂不可用”，总计标记为不完整。修改账号后不沿用旧账号数据。
- 运行统计逻辑测试：`python3 -m unittest discover -s tests -v`。
