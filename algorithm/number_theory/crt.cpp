#include <iostream>
using namespace std;

typedef long long ll;
typedef __int128 int128;

int n;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) { x = 1; y = 0; return a;}
    ll d = exgcd(a, b, y, x);
    y -= a / b * x;
    return d;
}

ll crt(ll m[], ll r[])
{
    ll M = 1, ans = 0;
    for (int i = 1; i <= n; i++) M *= m[i];
    for (int i = 1; i <= n; i++)
    {
        ll c = M / m[i], x, y;
        exgcd(c, m[i], x, y);
        ans = (ans + r[i] * c * x % M) % M;
    }
    return (ans % M + M) % M;
}

ll excrt(ll m[], ll r[])
{
    ll m1 = m[1], r1 = r[1], k1, k2;
    for (int i = 2; i <= n; i++)
    {
        ll m2 = m[i], r2 = r[i];
        ll d = exgcd(m1, m2, k1, k2);
        if ((r2 - r1) % d != 0) return -1;
        k1 = k1 * ((r2 - r1) / d);
        k1 = (k1 % (m2 / d) + m2 / d) % (m2 / d);
        r1 = k1 * m1 + r1;
        m1 = m1 * (m2 / d);
    }
    return (r1 % m1 + m1) % m1;
}

int main()
{

    return 0;
}