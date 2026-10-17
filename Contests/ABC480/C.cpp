#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    ll n, k, t;
    cin >> n >> k >> t;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll ans = 0;
    ll stop = a[0] + k;

    if (a[0] >= t) {
        cout << (t + k - 1) / k << endl;
        return;
    }

    if (a[0] > 0) {
        ans += (a[0] + k - 1) / k;
    }

    for (int i = 1; i < n && a[i] < t; ++i) {
        if (a[i] > stop) {
            ans += (a[i] - stop + k - 1) / k;
        }
        stop = a[i] + k;
    }

    if (stop < t) {
        ans += (t - stop + k - 1) / k;
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
