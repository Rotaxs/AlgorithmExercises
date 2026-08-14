#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    ll n, m, a, b; cin >> n >> m >> a >> b;
    ll ans = 0;
    for (ll x = 0; x <= n / 2 && x <= m; x++)
    {
        ll y = min(n - 2 * x, (m - x) / 2);
        if (y < 0) continue;
        ans = max(ans, a * x + b * y);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    // cin >> _;
    while (_--) solve();
    
    return 0;
}
