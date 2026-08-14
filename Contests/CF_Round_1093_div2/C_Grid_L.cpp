#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll p, q;
    cin >> p >> q;
    ll k = 2 * p + 4 * q + 1;
    int n, m;
    for (ll x = 3, y; x * x <= k; x++)
    {
        if (k % x == 0)
        {
            y = k / x;
            n = (x - 1) / 2; m = (y - 1) / 2;
            if (n >= 1 && m >= 1 && q <= n * m + min(n, m))
            {
                cout << n << ' ' << m << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
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