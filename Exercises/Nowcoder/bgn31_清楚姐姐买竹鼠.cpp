#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    ll a, b, x; cin >> a >> b >> x;
    ll ans = 0;
    if (3 * a > b)
    {
        ans += b * (x / 3);
        ans += min(a * (x % 3), b);
    }
    else
    {
        ans += a * x;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    
    return 0;
}