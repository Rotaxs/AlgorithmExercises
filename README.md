# Algorithm Exercises

算法竞赛练习仓库，记录日常刷题、比赛代码和算法模板。

<!-- OJ-STATS:START -->
## 刷题统计

| 平台 | 账号 | 通过题数 | 上次成功更新（北京时间） | 状态 |
| --- | --- | ---: | --- | --- |
| 洛谷 | [1817237](https://www.luogu.com.cn/user/1817237) | 343 | 2026-09-25 13:02:15 | 正常 |
| 牛客 | [439254888](https://ac.nowcoder.com/acm/contest/profile/439254888) | 129 | 2026-09-25 13:02:15 | 正常 |
| 力扣中国站 | [rotaxis](https://leetcode.cn/u/rotaxis/) | 9 | 2026-09-25 13:02:15 | 正常 |
| Codeforces | [rotaxis](https://codeforces.com/profile/rotaxis) | 86 | 2026-09-25 13:02:15 | 正常 |
| AtCoder | [rotas](https://atcoder.jp/users/rotas) | 45 | 2026-09-25 13:02:15 | 正常 |
| VJudge | [rotas](https://vjudge.net/user/rotas) | 8 | 2026-09-25 13:02:15 | 正常 |

**总通过题数：620**

平台内按题目去重，跨平台同题分别计数；每天北京时间 08:17 左右自动更新。
<!-- OJ-STATS:END -->

## 仓库内容

| 路径 | 内容 |
| --- | --- |
| [`Contests/`](Contests/) | AtCoder、Codeforces、牛客、ICPC/CCPC、CSP 等比赛代码 |
| [`Exercises/`](Exercises/) | 洛谷、牛客、LeetCode、Codeforces 等平台练习 |
| [`algorithm/`](algorithm/) | 数据结构、图论、数论、动态规划等算法实现 |
| [`notes/`](notes/) | 按主题整理的算法笔记，可用 Pandoc 构建 PDF |
| [`template.cpp`](template.cpp) | C++17 单文件提交模板 |

## 代码约定

- 以 C++17 为主，采用单文件提交；文件名通常包含平台前缀和题号。
- `template.cpp` 提供快速 I/O 和多测 `solve()` 骨架。
- 笔记正文位于 `notes/chapters/`，运行 `make -C notes pdf` 可生成 PDF。

## 更新统计

账号配置见 [`scripts/oj_accounts.json`](scripts/oj_accounts.json)。统计脚本仅使用 Python 标准库：

```bash
python3 scripts/update_oj_stats.py
python3 -m unittest discover -s tests -v
```

使用 `--dry-run` 可只查看统计结果，不修改文件。
