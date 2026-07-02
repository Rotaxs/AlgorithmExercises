// ======= 带空间压缩的 dp ========

#include <iostream>
using namespace std;

const int N = 1010;
int n, x;
int lose[N], win[N], use[N];
// dp[i] 表示用不超过 i 元能获得的最大经验
long long dp[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> lose[i] >> win[i] >> use[i];

    // 下面的代码是错误的
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = x; j >= 0; j--)
    //     {
    //         // 表示第 i 层的 j 位置已经修改了
    //         dp[j] = dp[j] + lose[i]; // 不打赢
    //         if (j >= use[i])
    //             // 这里 dp[j - use[i]] 是没有加上 lose 的
    //             // 这就导致一个加过 lose 的 dp[j] 和每加过的 dp[j - use[i]] 进行比较
    //             // 这是不合理的
    //             dp[j] = max(dp[j], dp[j - use[i]] + win[i]);
    //     }
    // }

    for (int i = 1; i <= n; i++)
    {
        // 到达第 i 层
        // 先全部加 lose[i]
        for (int j = 0; j <= x; j++)
            dp[j] += lose[i];

        // 再考虑“打赢”的情况（倒序）
        for (int j = x; j >= use[i]; j--)
            // 如果判断赢的收益更大，就把 lose 改为 win
            dp[j] = max(dp[j], dp[j - use[i]] - lose[i] + win[i]);
    }
    cout << dp[x] * 5 << '\n';
    return 0;
}

// ======= 二维 dp ========

// #include <iostream>
// using namespace std;

// const int N = 1010;
// int n, x;
// int lose[N], win[N], use[N];
// // dp[i][j] 表示考虑完前 i 个对手，用药量不超过 j 的情况下获得的最大经验
// long long dp[N][N];

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n >> x;
//     for (int i = 1; i <= n; i++)
//         cin >> lose[i] >> win[i] >> use[i];
    
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j <= x; j++)
//         {
//             dp[i][j] = dp[i - 1][j] + lose[i];
//             if (j >= use[i])
//                 dp[i][j] = max(dp[i][j], dp[i - 1][j - use[i]] + win[i]);
//         }
//     }
//     cout << dp[n][x] * 5 << '\n';
//     return 0;
// }