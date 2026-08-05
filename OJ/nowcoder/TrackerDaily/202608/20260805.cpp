#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 1e18;

void solve()
{
    int n; cin >> n;
    ll mx = 0, mi = inf;
    for (int i = 1; i <= n; ++i) {
        ll a; cin >> a;
        mx = max(mx, a);
        mi = min(mi, a);
    }
    cout << mx - mi << ' ' << ((mx + mi + 1) >> 1) << endl;
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