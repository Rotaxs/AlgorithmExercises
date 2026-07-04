#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1), dp(n + 1, inf);
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    dp[n] = 0;
    function<int(int)> dfs = [&](int i) {
        if (dp[i] != inf) return dp[i];
        else if (vis[i]) return inf;
        vis[i] = true;
        int res = inf;
        if (a[i] < 0)
        {
            for (int j = 1; j <= max(1, i + a[i]); j++)
                res = min(res, dfs(j));
        }
        else if (a[i] > 0)
        {
            for (int k = 1; k <= a[i]; k++)
                res = min(res, dfs(i + k));
        }
        return dp[i] = res;
    };
    dfs(1);
    cout << dp[1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    
    return 0;
}