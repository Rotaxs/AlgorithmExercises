#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 int128;
const int N = 15;
int n;
int m[N], a[N];

ll qpow(ll a, ll n)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret *= a;
        a *= a;
        n >>= 1;
    }
    return ret;
}

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll inv(ll a, ll p)
{
    ll x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}

void solve()
{
    cin >> n;
    ll M = 1;
    int128 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i] >> a[i];
        M *= m[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + (int128)a[i] * (M / m[i]) * inv(M / m[i], m[i])) % M;
    }
    cout << (ll)ans << '\n';
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