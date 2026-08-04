#include <bits/stdc++.h>
using namespace std;

#define N 100050

int i, j, k, n, m, t, vis[N], f[N];
vector<pair<int, int>> v[N];

void dfs(int x, int dep)
{
    if (x == n)
    {
        for (i = 1; i <= n; i++)
            if (!vis[i])
                f[i] = min(f[i], dep);
        return;
    }
    for (auto [y, id] : v[x])
        if (!vis[id])
        {
            vis[id] = 1;
            dfs(y, dep + 1);
            vis[id] = 0;
        }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> j >> k;
        f[i] = 1e9;
        v[j].push_back({k, i});
        v[k].push_back({j, i});
    }
    dfs(1, 0);
    for (i = 1; i <= n; i++)
    {
        cout << (f[i] > 1e6 ? -1 : f[i]) << '\n';
    }
}
