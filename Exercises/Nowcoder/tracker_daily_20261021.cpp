#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int MOD = 99824353;

ll qpow(ll a, ll n) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return ret;
}

void solve() {
    ll n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    if (n == 2) {
        cout << 1 << endl;
        return;
    }

    ll ans = ((n % MOD) * ((n - 1) % MOD) % MOD) * (qpow(2, n - 3) % MOD) % MOD;
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
