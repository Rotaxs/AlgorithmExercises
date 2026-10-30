#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<ll> suf(n + 2, 0);
    for (int i = n; i >= 1; --i) {
        suf[i] = suf[i + 1] + a[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += a[i] + suf[i + 1];
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
