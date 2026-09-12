#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    ll n, s, l;
    cin >> n >> s >> l;
    vector<ll> a(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> a[i];
    }

    int ans = 0;

    // -> right
    for (int i = 0; i <= s - 1; ++i) {
        ll dist = 0;
        int cur = 1;
        for (int j = 1; j <= i; ++j) {
            if (dist + a[s - j + 1] <= l) {
                dist += a[s - j + 1];
                ++cur;
            } else {
                break;
            }
        }
        if (dist * 2 > l) {
            ans = max(ans, cur);
            continue;
        }
        dist *= 2;
        for (int j = 1; j <= n - s; ++j) {
            if (dist + a[s + j] <= l) {
                dist += a[s + j];
                ++cur;
            } else {
                break;
            }
        }
        ans = max(ans, cur);
    }

    // <- left
    for (int i = 0; i <= n - s; ++i) {
        ll dist = 0;
        int cur = 1;
        for (int j = 1; j <= i; ++j) {
            if (dist + a[s + j] <= l) {
                dist += a[s + j];
                ++cur;
            } else {
                break;
            }
        }
        if (dist * 2 > l) {
            ans = max(ans, cur);
            continue;
        }
        dist *= 2;
        for (int j = 1; j <= s - 1; ++j) {
            if (dist + a[s - j + 1] <= l) {
                dist += a[s - j + 1];
                ++cur;
            } else {
                break;
            }
        }
        ans = max(ans, cur);
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
