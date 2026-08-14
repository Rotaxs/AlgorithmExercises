#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    ll a, b, t; cin >> a >> b >> t;
    map<pair<ll, ll>, bool> mp;
    function<bool(ll, ll)> dfs = [&](ll x, ll y) {
        if (x == t || y == t) return true;
        if (x > y) swap(x, y);
        if (mp.count({x, y})) return mp[{x, y}];
        mp[{x, y}] = false;
        return mp[{x, y}] = dfs(x | y, y) || dfs(x & y, y) || dfs(x ^ y, y) ||
                            dfs(x, x | y) || dfs(x, x & y) || dfs(x, x ^ y);
    };
    cout << (dfs(a, b) ? "YES\n" : "NO\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while (t--) solve();
    
    return 0;
}