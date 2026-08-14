#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 2e9;

void solve()
{
    int n; cin >> n;
    unordered_map<int, pair<int, ll>> mp;
    for (int i = 1; i <= n; i++)
    {
        int x, st = 0; cin >> x;
        while (x > 2)
        {
            mp[x].first++; mp[x].second += st; // 操作次数具有可加性
            if (x & 1) x++;
            else x /= 2;
            st++;
        }
        if (st == 0) st = 0;
        mp[1].first++; mp[2].first++;
        if (x == 1) mp[1].second += st, mp[2].second += st + 1;
        else mp[2].second += st, mp[1].second += st + 1;
    }
    ll ans = inf;
    for (auto &[x, info] : mp)
    {
        if (info.first == n) ans = min(ans, info.second);
    }
    cout << ans << '\n';
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