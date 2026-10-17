#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    vector<ll> p(n + 1), s(n + 1), c(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];

        p[i] = p[i - 1] + a[i];
        s[i] = s[i - 1] + p[i];
        c[i] = c[i - 1] + i;
    }

    auto query = [&](ll x) -> ll {
        if (x == 0) return 0;
        int k = lower_bound(c.begin() + 1, c.end(), x) - c.begin();
        ll pos = x - c[k - 1];
        return s[k - 1] + p[pos];
    };

    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << query(r) - query(l - 1) << endl;
    }
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
