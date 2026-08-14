#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 1e3 + 10;
const int M = N / 2;

int vis[N], a[N], b[N];
ll dp[N][5];

void solve()
{
    int n, C, m; cin >> n >> C >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        vis[u] = vis[v] = true;
        for (int j = C; j >= 0; j--)
        {
            for (int k = 4; k >= 1; k--)
            {
                if (j - a[u] >= 0)
                    dp[j][k] = max(dp[j][k], dp[j - a[u]][k - 1] + b[u]);
                if (j - a[v] >= 0)
                    dp[j][k] = max(dp[j][k], dp[j - a[v]][k - 1] + b[v]);
                if (j - a[u] - a[v] >= 0 && k - 2 >= 0)
                    dp[j][k] = max(dp[j][k], dp[j- a[u] - a[v]][k - 2] + b[u] + b[v] + w);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        for (int j = C; j >= a[i]; j--)
        {
            for (int k = 4; k >= 1; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - a[i]][k - 1] + b[i]);
            }
        }
    }

    cout << dp[C][4] << endl;
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