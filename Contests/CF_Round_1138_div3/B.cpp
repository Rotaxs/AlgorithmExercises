#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    ll n, k, p; cin >> n >> k >> p;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<ll> suf(n + 2, 0);
    for (int i = n; i >= 1; --i) suf[i] = suf[i + 1] + a[i];
    ll ans = 0;
    for (int t = 0; t * k <= n; ++t) {
        ans = max(ans, t * p + suf[t * k + 1]);
    }
    cout << ans << endl;
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
