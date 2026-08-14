#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 int128;

const int N = 1e5 + 10;
int n;
ll m[N], r[N];

ll exgcd(int128 a, int128 b, int128 &x, int128 &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll excrt(ll m[], ll r[])
{
    int128 m1 = m[1], r1 = r[1], m2, r2;
    int128 k1, k2;
    for (int i = 2; i <= n; i++)
    {
        m2 = m[i]; r2 = r[i];
        ll d = exgcd(m1, m2, k1, k2);
        if ((r2 - r1) % d != 0) return -1;
        k1 = k1 * ((r2 - r1) / d);
        k1 = (k1 % (m2 / d) + (m2 / d)) % (m2 / d);
        r1 = k1 * m1 + r1;
        m1 = m1 * (m2 / d);
    }
    return (ll)((r1 % m1 + m1) % m1);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> m[i] >> r[i];
    ll ans = excrt(m, r);
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