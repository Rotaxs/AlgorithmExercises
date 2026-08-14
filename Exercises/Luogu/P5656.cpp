#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


void solve()
{
    ll a, b, c, x, y;
    cin >> a >> b >> c;
    ll d = exgcd(a, b, x, y);
    if (c % d != 0) { cout << -1 << '\n'; return; }
    x = x * c / d; y = y * c / d;
    int m = b / d, n = a / d;
    x = (x % m + m) % m; 
    if (x == 0) x = m;
    y = (c - a * x) / b;
    if (y > 0)
    {
        ll cnt = (y - 1) / n + 1;
        ll minx = x;
        ll miny = (y - 1) % n + 1;
        ll maxx = x + (cnt - 1) * m;
        ll maxy = y;
        cout << cnt << ' ' << minx << ' ' << miny << ' ' << maxx << ' ' << maxy << '\n';
    }
    else
    {
        ll minx = x; // 最小正整数解
        ll maxy = y; // 最大负整数解
        ll miny = (y % n + n) % n;
        if (miny == 0) miny = n; // 最小正整数解
        ll maxx = (c - b * miny) / a; // 最大负整数解
        cout << minx << ' ' << miny << '\n';
    }
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