#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return (!b ? a : gcd(b, a % b)); }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    ll ans = lcm(a, lcm(b, c));
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