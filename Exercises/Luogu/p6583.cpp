#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (ll x = 1; x <= n; x++)
    {
        for (ll y = 1; y <= n; y++)
        {
            ll tx = x, ty = y;
            ll d = gcd(x, y);
            tx /= d; ty /= d;
            while (ty % 2 == 0) ty /= 2;
            while (ty % 5 == 0) ty /= 5;
            if (ty == 1) ans++;
        }
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