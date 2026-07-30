#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 1e18;

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(m));
    vector<int> s(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> d[i][j];
        }
        string st; cin >> st;
        for (int j = 0; j < m; ++j) {
            if (st[j] == 'A') {
                s[i] |= 1 << j;
            }
        }
    }

    int maxSt = 1 << m;
    vector<ll> dp(maxSt, inf);
    vector<vector<ll>> cost(maxSt, vector<ll>(m, 0));

    dp[0] = 0;
    for (int S = 0; S < maxSt; ++S) {   
        for (int j = 0; j < m; ++j) {
            if (S & (1 << j)) continue;
            ll cost = 0;
            for (int i = 0; i < n; ++i) {
                if ((S | s[i]) != s[i]) continue;
                cost += d[i][j];
            }
            dp[S | (1 << j)] = min(dp[S | 1 << j], dp[S] + cost);
        }
    }
    cout << dp[maxSt - 1] << endl;
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