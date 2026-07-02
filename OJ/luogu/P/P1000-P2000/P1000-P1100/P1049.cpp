// ========== 布尔背包 =========

#include <iostream>
#include <algorithm>
using namespace std;

int v, n;
int volume[35];
// 能否凑出 i 体积的物品
bool dp[20005];


int main()
{
    cin >> v >> n;
    for (int i = 1; i <= n; i++)
        cin >> volume[i];
    dp[0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = v; j >= volume[i]; j--)
        {
            // 只要上一层的容量不超过 j - volume[i]
            // 那么这一层就能够加上第 i 件物品
            // if (dp[j - volume[i]]) dp[j] = true;
            // 简化写法
            dp[j] |= dp[j - volume[i]];
        }
    }

    // 逆序以找到 j 的最大值
    for (int j = v; j >= 0; j--)
    {
        if (dp[j])
        {
            cout << v - j << '\n';
            break;
        }
    }
    return 0;
}

// ========== 记忆化搜索 ===========

// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;

// int v, n;
// int volume[35];
// // dp[i][j] 表示在第 i 件物品时的体积为 j
// // 而后能装的最大体积
// int dp[35][20005];

// // 返回从 p + 1 个物品开始选，能获得的最大的额外体积
// int dfs(int p, int vol)
// {
//     if (p == n) return 0;
//     if (dp[p][vol] != -1) return dp[p][vol];
//     int res = 0;
//     // 在不超过 v 的情况下可以选择第 p + 1 件物品
//     if (vol + volume[p + 1] <= v)
//         res = max(res, volume[p + 1] + dfs(p + 1, vol + volume[p + 1]));
//     // 不选第 p + 1 件物品
//     res = max(res, dfs(p + 1, vol));
//     return dp[p][vol] = res;
// }

// int main()
// {
//     cin >> v >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> volume[i];
//     memset(dp, -1, sizeof(dp));
//     int ans = dfs(0, 0);
//     cout << v - ans << '\n';
//     return 0;
// }

// ====== dfs + 剪枝 =======

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int v, n;
// int volume[35];
// int suf[35];
// int ans = 0;


// void dfs(int p, int vol)
// {
//     // 如果当前体积加上从第 p + 1 个元素（因为第 p 个元素已经判断完）
//     // 不超过 ans 说明其一定不是最优方案
//     if (vol + suf[p + 1] <= ans)
//         return;
//     if (p == n)
//     {
//         ans = max(ans, vol);
//         return;
//     }
//     // 在不超过 v 的情况下可以选择第 p + 1 件物品
//     if (vol + volume[p + 1] <= v)
//         dfs(p + 1, vol + volume[p + 1]);
//     // 不选第 p + 1 件物品
//     dfs(p + 1, vol);
// }

// int main()
// {
//     cin >> v >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> volume[i];
//     // 处理后缀和，便于剪枝
//     suf[n + 1] = 0;
//     for (int i = n; i >= 0; i--)
//         suf[i] = suf[i + 1] + volume[i];
//     dfs(0, 0);
//     cout << v - ans << '\n';
//     return 0;
// }

// ======== 暴搜 =======

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int v, n;
// int volume[35];
// int ans = 0;

// void dfs(int p, int vol)
// {
//     if (p == n)
//     {
//         ans = max(ans, vol);
//         return;
//     }
//     // 在不超过 v 的情况下可以选择第 p + 1 件物品
//     if (vol + volume[p + 1] <= v)
//         dfs(p + 1, vol + volume[p + 1]);
//     // 不选第 p + 1 件物品
//     dfs(p + 1, vol);

// }

// int main()
// {
//     cin >> v >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> volume[i];
//     dfs(0, 0);
//     cout << v - ans << '\n';
//     return 0;
// }