#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 1e5 + 10;

int fa[M << 1];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y)
{
    int rx = find(x), ry = find(y);
    if (rx == ry) return;
    fa[ry] = rx;
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> r(n + 1);
    vector<pair<int, int>> e(n + 1, {-1, -1});
    for (int i = 1; i <= n; i++) cin >> r[i];
    for (int i = 1; i <= m; i++)
    {
        int cnt; cin >> cnt;
        for (int j = 1; j <= cnt; j++)
        {
            int d; cin >> d;
            if (e[d].first == -1) e[d].first = i;
            else e[d].second = i;
        }
    }
    for (int i = 1; i <= 2 * m; i++) fa[i] = i;
    for (int i = 1; i <= n; i++)
    {
        int x = e[i].first, y = e[i].second;
        if (r[i] == 1)
        {
            unite(x, y);
            unite(x + m, y + m);
        }
        else 
        {
            unite(x, y + m);
            unite(y, x + m);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (find(i) == find(i + m)) 
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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