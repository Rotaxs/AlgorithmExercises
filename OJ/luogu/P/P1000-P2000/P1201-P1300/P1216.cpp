#include <bits/stdc++.h>
using namespace std;

const int MAXR = 1010;
int f[MAXR][MAXR] = {0};
// dp[i][k] 表示到达第 i 层第 k 个结点的最大权值
// dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - 1]) + f[i][k]
int dp[MAXR][MAXR] = {0};

int main()
{
    int n;
    cin >> n;
    int r, c;
    for (int r = 1; r <= n; r++)
        for (int c = 1; c <= r; c++)
            cin >> f[r][c];

    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= i; k++)
        {
            dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - 1]) + f[i][k];
        }
    }
    int res = dp[n][1];
    for (int i = 1; i <= n; i++)
    {
        res = max(dp[n][i], res);
    }

    cout << res << '\n';
    return 0;
}