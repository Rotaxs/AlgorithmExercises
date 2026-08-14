// ========= 空间压缩 dp ===========

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 110, M = 110;
const int MOD = 1e6 + 7;

int n, m;
int a[N];
// // dp[i][j] 前 i 种植物，选 j 盆植物的情况下能求得的方案数
// // dp[i][j] += dp[i - 1][j - k] 0 <= k <= a[i]
// int dp[N][M];

// dp[j] 表示选 j 盆植物的情况下能求得的方案数
// dp[j] += dp[j - k]
int dp[M];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            // 注意这里 k 从 1 开始，否则 dp[j] 会加上自己，导致重复计算
            for (int k = 1; k <= a[i]; k++)
            {
                if (j >= k)
                    dp[j] = (dp[j - k] + dp[j]) % MOD;
            }
        }
    }

    cout << dp[m] << '\n';
    return 0;
}

// ============ dp =============

// #include <iostream>
// #include <cstring>
// #include <algorithm>
// using namespace std;

// typedef long long ll;
// const int N = 110, M = 110;
// const int MOD = 1e6 + 7;

// int n, m;
// int a[N];
// // dp[i][j] 前 i 种植物，选 j 盆植物的情况下能求得的方案数
// // dp[i][j] += dp[i - 1][j - k] 0 <= k <= a[i]
// int dp[N][M];

// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     dp[0][0] = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j <= m; j++)
//         {
//             for (int k = 0; k <= a[i]; k++)
//             {
//                 if (j >= k)
//                     dp[i][j] = (dp[i - 1][j - k] + dp[i][j]) % MOD;
//             }
//         }
//     }
    
//     cout << dp[n][m] << '\n';
//     return 0;
// }

// =============== 记忆化搜索 ===============

// #include <iostream>
// #include <cstring>
// #include <algorithm>
// using namespace std;

// typedef long long ll;
// const int N = 110, M = 110;
// const int MOD = 1e6 + 7;

// int n, m;
// int a[N];
// // dp[i][j] 表示考虑完第 i 种植物后，在已选 j 盆植物的情况下能求得的方案数
// int dp[N][M];

// ll dfs(int p, int sum)
// {
//     if (dp[p][sum] != -1) return dp[p][sum];
//     if (p > n) return sum == m;
//     ll ans = 0;
//     for (int i = 0; i <= a[p]; i++)
//     {
//         if (sum + i <= m)
//             ans = (dfs(p + 1, sum + i) + ans) % MOD;
//     }
//     return dp[p][sum] = ans;
// }

// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     memset(dp, -1, sizeof dp);
//     int ans = dfs(1, 0);
//     cout << ans << '\n';
//     return 0;
// }

// =============== 暴搜 ================

// #include <iostream>
// #include <algorithm>
// using namespace std;

// typedef long long ll;
// const int N = 110, M = 110;
// const int MOD = 1e6 + 7;

// int n, m;
// int a[N];

// ll dfs(int p, int sum)
// {
//     if (p > n) return sum == m;
//     ll ans = 0;
//     for (int i = 0; i <= a[p]; i++)
//     {
//         if (sum + i <= m)
//             ans = (dfs(p + 1, sum + i) + ans) % MOD;
//     }
//     return ans;
// }

// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     int ans = dfs(1, 0);
//     cout << ans << '\n';
//     return 0;
// }