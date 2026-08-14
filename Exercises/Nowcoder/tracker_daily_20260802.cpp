#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
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
    int n; cin >> n;
    string s; cin >> s;
    ll ans = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        int d = s[i] - '0';
        if (!(d & 1)) ans = (ans + c + 1) % MOD;
        if (d == 0) c = (c << 1) % MOD;
        else c = ((c << 1) + 1) % MOD;
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