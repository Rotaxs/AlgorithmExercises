#include <bits/stdc++.h>
using namespace std;

const int T = 1010;
const int M = 110;

int cost[M], value[M];
int dp[T] = {0};

int main()
{
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
        cin >> cost[i] >> value[i];
    for (int i = 1; i <= m; i++)
    {
        for (int j = t; j >= cost[i]; j--)
            dp[j] = max(dp[j - cost[i]] + value[i] , dp[j]);
    }
    cout << dp[t] << '\n';
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int T = 1010;
// const int M = 110;

// int cost[M], value[M];
// // dp[i][j] 表示判断完前 i 个草药后，用 j 时采的草药的最大价值
// // 若不采第 i 个草药，dp[i][j] = dp[i - 1][j]]
// // 采第 i 个草药 dp[i][j] = dp[i - 1][j - cost[i]] + value[i]
// // 因此 dp[i][j] = max(dp[i - 1][j]], dp[i - 1][j - cost[i]] + value[i])
// int dp[M][T] = {0};

// int main()
// {
//     int t, m;
//     cin >> t >> m;
//     for (int i = 1; i <= m; i++)
//         cin >> cost[i] >> value[i];
//     for (int i = 1; i <= m; i++)
//     {
//         for (int j = 0; j <= t; j++)
//         {
//             if (j < cost[i])
//                 dp[i][j] = dp[i - 1][j];
//             else
//                 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + value[i]);
//         }
//     }
//     cout << dp[m][t] << '\n';
//     return 0;
// }