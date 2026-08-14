#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;
const int N = 3e6 + 10;
int fac[N], inv_f[N];

ll qpow(ll a, ll n, ll m)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = ret * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return ret;
}

void build(int n, int m)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % m;
    inv_f[n] = qpow(fac[n], m - 2, m);
    for (int i = n - 1; i >= 0; i--)
        inv_f[i] = 1LL * inv_f[i + 1] * (i + 1) % m;
}

ll C(int n, int m)
{
    if (n < m || m < 0) return 0;
    return 1LL * fac[n] * inv_f[m] % MOD * inv_f[n - m] % MOD;
}

void solve()
{
    int a, b, c; cin >> a >> b >> c;
    build(N - 1, MOD);
    ll ans = 0;
    for (int i = 1; i <= b; i++)
    {
        ans = (ans + ((C(b + 1, i) * C(a - 1, i - 1) % MOD) * C(b + c - i, b - i)) % MOD) % MOD;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();
    
    return 0;
}
