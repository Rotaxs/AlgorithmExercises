#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int k;
// c[i][j] 表示组合数 C[i][j] 除以 k 得到的余数
int c[2001][2001];
// ans[i][j] 表示 n = i, m = j 时的方案数
int ans[2001][2001];

void build()
{
    c[0][0] = 1 % k;
    int flag = 0;
    for (int i = 1; i <= 2000; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + (c[i][j] == 0);
        }
        // 前缀和依赖上面、左边和左上的前缀和
        // 左边和左上都是合法杨辉三角
        // 因此只需将上面补齐
        // 根据 ans[i][j] 的定义，就 ans[i][i + 1] = ans[i][i]
        // 因为 j <= min(m, i)，即有 j<=i，故即使 j > i，也不会有新的贡献
        ans[i][i + 1] = ans[i][i];
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    cout << (n >= m ? ans[n][m] : ans[n][n]) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t >> k;
    build();
    while (t--)
        solve();

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// int k;
// // c[i][j] 表示组合数 C[i][j] 除以 k 得到的余数
// int c[2001][2001];
// // ans[i][j] 表示 n = i, m = j 时的方案数
// int ans[2001][2001];

// void build()
// {
//     c[0][0] = 1 % k;
//     int flag = 0;
//     for (int i = 1; i <= 2000; i++)
//     {
//         c[i][0] = 1;
//         // 需要补完矩形，才能计算二维前缀和
//         // 比如 ans[3][3] = ans[2][3] + ans[3][2] - ans[2][2] + flag
//         // 这里需要依赖 ans[2][3]
//         for (int j = 1; j <= 2000; j++)
//         {
//             // 只算组合数有意义的部分
//             if (j <= i)
//             {
//                 c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
//                 // 计算对前缀和的贡献
//                 flag = c[i][j] == 0;
//             }
//             else
//             {
//                 // 如果超出了杨辉三角的范围，贡献为 0
//                 // ans[i][j] 就继承自前面的
//                 flag = 0;
//             }
//             // ans[i][j] = 继承 + 组合数贡献
//             ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + flag;
//         }
//     }
// }

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     cout << ans[n][m] << '\n';
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t;
//     cin >> t >> k;
//     build();
//     while (t--) solve();

//     return 0;
// }