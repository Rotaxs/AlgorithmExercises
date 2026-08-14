// ========================== dp + 差分数组 ======================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2010;
int dp[N];
int diff[N];
int ans[N];

void solve()
{
    int n;
    cin >> n;
    char c;
    int cur = 0, pre = 0;
    // 输入和 dp 同时处理，少开一个 mat 数组
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            int a = c - '0';

            cur = dp[j];
            if (a == 1)
                dp[j] = min(min(dp[j], dp[j - 1]), pre) + 1;
            else
                dp[j] = 0;
            pre = cur;
            // 一个数对原数的影响从 1 开始，超过自己时消失
            diff[1]++;
            diff[dp[j] + 1]--;
        }
    }
    // 通过前缀和还原数组
    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[i - 1] + diff[i];
        cout << ans[i] << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();

    return 0;
}

// ===================== dp + 前缀和 =========================

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// const int N = 2010;
// int mat[N][N];
// int dp[N];
// int cnt[N];

// void solve()
// {
//     int n;
//     cin >> n;
//     char c;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cin >> c;
//             mat[i][j] = c - '0';
//         }
//     }
//     int cur = 0, pre = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cur = dp[j];
//             if (mat[i][j] == 1)
//                 dp[j] = min(min(dp[j], dp[j - 1]), pre) + 1;
//             else
//                 dp[j] = 0;
//             pre = cur;
//             cnt[dp[j]]++;
//         }
//     }
//     // 将大数的贡献累积到小数上
//     // 后缀和处理思路（最优解）
//     for (int i = n - 1; i >= 1; i--)
//         cnt[i] += cnt[i + 1];
//     // 前缀和处理思路   
//     // for (int i = 1; i <= n; i++)
//     // {
//     //     for (int j = i + 1; j <= n; j++)
//     //     {
//     //         cnt[i] += cnt[j];
//     //     }
//     // }
//     for (int i = 1; i <= n; i++) cout << cnt[i] << ' ';
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     // int t;
//     // cin >> t;
//     // while (t--) solve();

//     solve();

//     return 0;
// }