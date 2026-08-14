#include <bits/stdc++.h>
#define endl '\n'
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x)  << " (Line " << __LINE__ << ")" << endl
#else
#define debug(x)
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll M = 1e18;

ll qpow(ll a, ll n) {
    ll res = 1LL;
    while (n) {
        if (n & 1 && res > M / a) return M + 1;
        if (n & 1) res = res * a;
        if (a > M / a && n > 1) return M + 1;
        a = a * a;
        n >>= 1;
    }
    return res;
}

void solve()
{
    ll p, q, n = 2, ans; cin >> p >> q;

	while (1) {
        ans = qpow(p, q);
        if (ans > M) break;
        ++n;
        p = q; q = ans;
    }
    
    cout << n << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    // cin >> _;
    while (_--) solve();
    
    return 0;
}