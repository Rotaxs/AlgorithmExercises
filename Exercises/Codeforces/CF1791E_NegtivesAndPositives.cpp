#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 1e18;

void solve() {
    int n;
    cin >> n;
    // vector<ll> a(n + 1, 0);
    // for (int i = 1; i <= n; ++i) {
    //     cin >> a[i];
    // }

    // vector<array<ll, 2>> f(n + 1, {0, 0});
    // f[1][0] = a[1];
    // f[1][1] = -inf;
    // for (int i = 2; i <= n; ++i) {
    //     f[i][0] = max(f[i - 1][0] + a[i], f[i - 1][1] + a[i]);
    //     f[i][1] = max(f[i - 1][0] - a[i] - 2 * a[i - 1], f[i - 1][1] - a[i] + 2 * a[i - 1]);
    // }
    // cout << max(f[n][0], f[n][1]) << endl;

    bool zero = false;
    int cnt = 0;
    ll sum = 0, mn = inf;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        if (a == 0) {
            zero = true;
        } else {
            if (a < 0) {
                a = -a;
                ++cnt;
            }
            mn = min(mn, a);
        }
        sum += a;
    }

    if (zero || cnt % 2 == 0) {
        cout << sum << endl;
    } else {
        cout << sum - 2 * mn << endl;
    }
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
