#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll mx = 0;
    vector<ll> h(n);
    for (ll& x : h) {
        cin >> x;
        mx = max(mx, x);
    }

    auto check = [&](ll x) -> bool {
        vector<ll> tmp = h;
        ll cost = 0;
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            ll diff = abs(tmp[i] - tmp[j]);
            if (diff > x) {
                if (tmp[i] > tmp[j]) {
                    tmp[j] = tmp[i] - x;
                } else {
                    tmp[i] = tmp[j] - x;
                }
                cost += diff - x;
            }
        }
        for (int i = n - 1; i > 0; --i) {
            int j = i - 1;
            ll diff = abs(tmp[i] - tmp[j]);
            if (diff > x) {
                if (tmp[i] > tmp[j]) {
                    tmp[j] = tmp[i] - x;
                } else {
                    tmp[i] = tmp[j] - x;
                }
                cost += diff - x;
            }
        }

        return cost <= k;
    };

    int p = max_element(h.begin(), h.end()) - h.begin();
    rotate(h.begin(), h.begin() + p, h.end());

    ll l = -1, r = mx + 1;
    while (l + 1 != r) {
        ll m = l + ((r - l) >> 1);
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << endl;
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
