#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;

long long qpow(ll a, ll n)
{
    long long ret = 1;
    while (n)
    {
        if (n & 1)
            ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return ret;
}

void solve()
{
    ll x, y;
    cin >> x >> y;
    if (x <= y)
    {
        cout << 1 << '\n';
        return;
    }
    // (y + 1) * 2 ^ (x - y - 1)
    cout << (y + 1) * qpow(2, x - y - 1) % MOD << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    
    return 0;
}