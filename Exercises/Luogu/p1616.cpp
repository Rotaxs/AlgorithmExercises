#include <bits/stdc++.h>
using namespace std;

const int T = 1e7 + 10;
int a[10010], b[10010];
// dp[i] 表示采 i 时间的药能获取的草药的最大价值
// dp[i] = max(dp[i - a[j]] + b[j])
long long dp[T] = {0};

int main()
{
    int t, m;
    cin >> t >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i] >> b[i];
    dp[0] = 0;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[j] <= i)
                dp[i] = max(dp[i], dp[i - a[j]] + b[j]);
        }
    }
    cout << dp[t] << '\n';
    return 0;
}