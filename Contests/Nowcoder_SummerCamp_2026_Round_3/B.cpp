#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int M = 998244353;
const int N = 2e6 + 10;

int inv[N], fac[N], inv_f[N];

ll qpow(ll a, ll n, ll p)
{
    ll ret = 1;
    while (n) {
        if (n & 1) ret = (ret * a) % p;
        a = (a * a) % p;
        n >>= 1;
    }
    return ret;
}

void build_inv(int n, int m)
{
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (ll)(m - m / i) * inv[m % i] % m;
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % m;
    inv_f[n] = qpow(fac[n], m - 2, m);
    for (int i = n - 1; i >= 0; i--)
        inv_f[i] = 1ll * inv_f[i + 1] * (i + 1) % m;
}

int C(int n, int m)
{
    if (n < m || m < 0) return 0;
    return 1ll * fac[n] * inv_f[m] % M * inv_f[n - m] % M;
}

void solve()
{
    int n, m, c, a, b; cin >> n >> m >> c >> a >> b;
    if (m < n || (m - n) % c != 0) {
        cout << 0 << endl;
        return;
    }
    int x = (m - n) / c, y = m - x;
    ll part1 = 1ll * n * inv[m] % M * C(m, x) % M;
    ll part2 = 1ll * qpow(a, x, M) * qpow(b - a, y, M) % M;
    ll part3 = qpow(qpow(b, m, M), M - 2, M);
    ll ans = part1 * part2 % M * part3 % M;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    build_inv(N - 1, M);

    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}