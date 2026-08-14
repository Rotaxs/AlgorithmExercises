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
    ll a, b, x, y;
    cin >> a >> b;
    exgcd(a, b, x, y);
    cout << ((x % b + b) % b) << '\n';
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