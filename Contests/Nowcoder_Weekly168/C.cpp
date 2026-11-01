#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n + 1), pre(n + 1, 0), suf(n + 2, 0);

    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        pre[i] = ((pre[i - 1] + a[i]) % m + m) % m;
    }

    for (int i = n; i >= 1; --i) {
        suf[i] = ((suf[i + 1] + a[i]) % m + m) % m;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (pre[i] == suf[i]) ++ans;
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
