#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> d(n + 1), a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        d[i] = a[i] - b[i];
    }

    sort(d.begin() + 1, d.end());

    ll ans = 0;
    for (int i = 2; i <= n; ++i) {
        int p = upper_bound(d.begin() + 1, d.begin() + i, -d[i]) - d.begin();
        ans += i - p;
    }

    cout << ans << endl;
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
