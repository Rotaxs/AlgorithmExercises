#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    ll n, m; cin >> n >> m;
    ll ans;
    if (m <= n - 1) ans = m * (m - 1) / 2;
    else ans = (n - 1) * (n - 2) / 2 - (m - n + 1);
    cout << max(ans, 0LL) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}