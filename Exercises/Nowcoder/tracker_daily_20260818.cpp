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

const int MOD = 1e9 + 7;

ll qpow(ll a, ll n) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return ret;
}

void solve()
{
    ll n; cin >> n;
    ll powFourN = qpow(4, n);
    ll powFourHalf = qpow(4, n / 2);
    ll powTwo = qpow(2, n / 2);
    ll diff = (powFourHalf - powTwo + MOD) % MOD;
    
    ll ans;
    if (n & 1) {
        ans = (powFourN + diff * 2 % MOD) % MOD;
    } else {
        ans = (powFourN + diff) % MOD;
    }
    cout << ans << endl;
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