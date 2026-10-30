#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<ll> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    vector<ll> pre(n + 1, -inf), suf(n + 2, -inf);
    for (int i = 1; i <= n; ++i) {
        pre[i] = max(pre[i - 1], b[i] + i);
    }
    for (int i = n; i >= 1; --i) {
        suf[i] = max(suf[i + 1], b[i] - i);
    }

    ll ans = 0;
    for (int i = 2; i <= n - 1; ++i) {
        ans = max(ans, pre[i - 1] + b[i] + suf[i + 1]);
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
