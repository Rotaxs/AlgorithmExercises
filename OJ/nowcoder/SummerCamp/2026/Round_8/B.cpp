#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

// const int inf = 0x3f3f3f3f;
// const ll inf  = 2e18;

const int MOD = 998244353;

void solve()
{
    int n, m; cin >> n >> m;
    vector<bool> vis(2 * n + 1, 0);
    bool ok = true;
    for (int i = 1; i <= m; ++i) {
        int a; cin >> a;
        if (a > 2 * n) ok = false;
        else vis[a] = true;
    }
    if (!ok) {
        cout << 0 << endl;
        return;
    }

    vector<vector<int>> dp(2 * n + 1, vector<int>(n + 2, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= 2 * n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j >= 1) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            if (!vis[i]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    cout << dp[2 * n][0] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}