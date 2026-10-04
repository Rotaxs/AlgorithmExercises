#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll qpow(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

void solve() {
    ll x, y;
    cin >> x >> y;
    unordered_map<ll, ll> pFac;

    auto getFactors = [&](ll n) {
        for (int i = 2; (ll)i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    n /= i;
                    cnt++;
                }
                pFac[i] += cnt;
            }
        }
        if (n > 1) ++pFac[n];
    };

    getFactors(x);
    getFactors(y);

    ll a = 1, b = 1;

    for (auto [p, cnt] : pFac) {
        a *= qpow(p, cnt / 2);
    }

    b = 1ll * x * y / a;

    cout << a << ' ' << b << endl;
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
