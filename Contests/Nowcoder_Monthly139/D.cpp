#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        pre[i] = pre[i - 1] + a;
    }

    vector<ll> f;
    int maxK = 1;
    ll cur = 0;
    while (1) {
        cur += (ll)3 * maxK;
        if (cur > n) break;
        f.push_back(cur);
        ++maxK;
    }

    ll ans = -1e18;
    for (int k = 1; k < maxK; ++k) {
        for (int i = f[k - 1]; i <= n; ++i) {
            ans = max(ans, pre[i] - pre[i - f[k - 1]]);
        }
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
