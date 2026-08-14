#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
    记忆化搜索
    当用 dfs 求最少步时，可考虑用最少步数组（不回溯）
    当用 dfs 求所有情况时，可考虑 vis 数组（回溯）
*/

int N, A, B;
vector<int> K;
// min_step[i] 表示从 A 到第 i 层的最少步
vector<int> min_step;
int ans = INT_MAX;

void dfs(int cur_f, int cnt)
{
    if (cnt >= ans)
        return;
    if (cnt >= min_step[cur_f])
        return;
    min_step[cur_f] = cnt;
    if (cur_f == B)
    {
        ans = cnt;
        return;
    }
    if (cur_f + K[cur_f] <= N)
        dfs(cur_f + K[cur_f], cnt + 1);
    if (cur_f - K[cur_f] >= 1)
        dfs(cur_f - K[cur_f], cnt + 1);
}

int main()
{
    cin >> N >> A >> B;
    K.resize(N + 1);
    min_step.resize(N + 1, INT_MAX);
    for (int i = 1; i <= N; i++)
        scanf("%d", &K[i]);
    dfs(A, 0);
    if (ans != INT_MAX)
        cout << ans << '\n';
    else
        cout << -1 << '\n';
    return 0;
}

// ========================================================

/*
    基本 bfs + 剪枝会 TLE
*/

// int N, A, B;
// vector<int> K;
// vector<bool> vis;
// int ans = INT_MAX;
// bool reached = false;

// void dfs(int cur_f, int cnt)
// {
//     // 剪枝：如果 cnt 已经大于 ans 了，就没有递归的必要了
//     if (cnt > ans)
//         return;
//     if (cur_f == B)
//     {
//         reached = true;
//         ans = min(ans, cnt);
//         return;
//     }
//     // 标记走过的楼层
//     vis[cur_f] = true;
//     // 往上走
//     if (cur_f + K[cur_f] <= N && !vis[cur_f + K[cur_f]])
//         dfs(cur_f + K[cur_f], cnt + 1);
//     // 往下走
//     if (cur_f - K[cur_f] >= 1 && !vis[cur_f - K[cur_f]])
//         dfs(cur_f - K[cur_f], cnt + 1);
//     // 回溯
//     vis[cur_f] = false;
// }

// int main()
// {
//     cin >> N >> A >> B;
//     K.resize(N + 1);
//     vis.resize(N + 1, false);
//     for (int i = 1; i <= N; i++)
//         scanf("%d", &K[i]);
//     dfs(A, 0);
//     if (reached)
//         cout << ans << '\n';
//     else
//         cout << -1 << '\n';
//     return 0;
// }