#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128_t int128;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void solve()
{
    int a, b;
    ll x = 0, y = 0;
    cin >> a >> b;  
    ll d = exgcd(a, b, x, y);
    ll m = b / d, n = a / d;

    x = (x % m + m) % m;
    if (x > 0) x -= m;
    y = (d - a * x) / b;

    cout << d << '\n';
    cout << -x << ' ' << y << '\n';
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