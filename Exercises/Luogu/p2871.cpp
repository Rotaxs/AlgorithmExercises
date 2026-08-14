#include <bits/stdc++.h>
using namespace std;

int w[3410], d[3410];
// dp[i] 表示重量为 i 时可以获得的最大价值
long long dp[13000];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> d[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= w[i]; j--)
        {
            dp[j] = max(dp[j - w[i]] + d[i], dp[j]);
        }
    }
    cout << dp[m] << '\n';
    return 0;
}