#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 1e18;

void solve() {
    int n; cin >> n;
    vector<ll> L(n + 1), P(n + 1);
    ll mx = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> L[i] >> P[i];
    }
    
    vector<ll> dp(n + 2, inf), ndp(n + 2, inf);
    dp[1] = 0;
    for (int i = 1; i <= n; ++i) {
        fill(ndp.begin(), ndp.end(), inf);
        for (int l = 1; l <= i; ++l) {
            if (dp[l] >= inf) continue;
            ndp[l] = min(ndp[l], dp[l]);
            if (l >= L[i]) ndp[l + 1] = min(ndp[l + 1], dp[l] + P[i]);
        }
        dp.swap(ndp);
    } 

    ll ans = inf;
    for (int l = 1; l <= n; ++l) {
        if (l >= L[n] && dp[l] < inf) ans = min(ans, dp[l] + P[n]);
    }
    cout << (ans >= inf ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}
