#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

i128 qpow(i128 a, i128 n, i128 m) {
    i128 res = 1;
    while (n) {
        if (n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

void solve() {
    ll x, n, m;
    cin >> x >> n >> m;
    m /= gcd(x, m);

    if (m == 1) {
        cout << "Yes" << endl;
        return;
    }

    int l = 0;
    for (ll t = x; t; t /= 10) ++l;

    i128 base = 1;
    for (int i = 0; i < l; ++i) base *= 10;
    i128 mod = (base - 1) * m;

    cout << (qpow(base, n, mod) == 1 ? "Yes" : "No") << endl;
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
