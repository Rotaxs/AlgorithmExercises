#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 1e3 + 10;
const int C = 1e3 + 10;
int cost[N], val[N];
int dp[N][C];

void solve()
{
    int n, c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= cost[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + val[i]);
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = c; j >= cost[i]; j--)
    //         dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
    // }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    // cin >> _;
    while (_--) solve();
    
    return 0;
}