#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

void solve()
{
    ll x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;
    ll a = n - m, b = l, c = x - y;
    if (a < 0) { a = -a; c = -c; }
    ll d = exgcd(a, b, x, y);
    int mod = b / d;
    if (c % d != 0) cout << "Impossible";
    else cout << ((x * c / d) % mod + mod) % mod << '\n';;
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