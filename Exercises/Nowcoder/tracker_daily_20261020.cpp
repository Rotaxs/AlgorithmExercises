#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll qpow(ll a, ll n) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret *= a;
        a *= a;
        n >>= 1;
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> factors;

    for (int p = 2; 1ll * p * p <= n; ++p) {
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                ++cnt;
            }
            factors.push_back({p, cnt});
        }
    }
    if (n != 1) {
        factors.push_back({n, 1});
    }

    int len = factors.size();
    ll ans = 1;
    ll cur = 1;
    for (int i = len - 1; i >= 0; --i) {
        int p = factors[i].first, cnt = factors[i].second;
        while (cnt--) {
            cur *= p;
            ans += cur;
        }
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
