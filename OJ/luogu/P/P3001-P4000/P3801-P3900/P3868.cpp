#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll excrt(vector<ll> &r, vector<ll> &m)
{
    ll m1 = m[1], r1 = r[1], k1, k2, m2, r2;
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
    return (r1 % m1 + m1) % m1;
}

void solve()
{
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    ll ans = excrt(a, b);
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