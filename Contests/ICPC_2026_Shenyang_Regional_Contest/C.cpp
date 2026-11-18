#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 1e18;

void solve() {
    ll n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    vector<vector<ll>> f(m + 1, vector<ll>(m + 1, inf));
    vector<ll> mn(m + 1, inf);
    
    f[0][0] = 0;
    mn[0] = 0;

    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        for (int u = 0; u <= m; ++u) {
            if (u == x) continue;
            f[x][u] = min({f[x][u], f[x][u] + b - a, f[u][x] + b - a, mn[u] + c - a});
            mn[x] = min(mn[x], f[x][u]);
        }
    }
    cout << 1ll * n * a + *min_element(mn.begin(), mn.end()) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}
