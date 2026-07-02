#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
const int M = 1e5 + 10;

struct { int to, ne; } edge[M];
int head[N], cnt;
int ans[N];

void add_edge(int u, int v)
{
    edge[++cnt] = {v, head[u]};
    head[u] = cnt;
}

void dfs(int u, int d)
{
    ans[u] = d;
    for (int e = head[u]; e; e = edge[e].ne)
    {
        int v = edge[e].to;
        if (ans[v]) continue;
        dfs(v, d);
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        add_edge(v, u);
    }

    for (int i = n; i >= 1; i--)
    {
        if (!ans[i])
            dfs(i, i);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
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