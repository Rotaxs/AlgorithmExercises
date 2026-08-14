#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e3 + 10;
const int M = 6e3 + 10;
const int inf = 0x3f3f3f3f;

struct { int u, v, w; } edge[M];
int dist[N];

void init(int n, int s)
{
    for (int i = 1; i <= n; i++) dist[i] = inf;
    dist[s] = 0;
}

bool bellman_ford(int n, int m)
{
    init(n, 1);
    for (int i = 1; i <= n; i++)
    {
        bool relax = false;
        for (int e = 1; e <= m; e++)
        {
            int u = edge[e].u, v = edge[e].v, w = edge[e].w;
            if (dist[u] == inf) continue;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                relax = true;
                if (i == n) return true;
            }
        }
        if (!relax) break;
    }
    return false;
}

void solve()
{
    int n, m; cin >> n >> m;
    int cnt = 0;
    while (m--)
    {
        int u, v, w; cin >> u >> v >> w;
        edge[++cnt] = {u, v, w};
        if (w >= 0)
            edge[++cnt] = {v, u, w};
    }
    cout << (bellman_ford(n, cnt) ? "YES" : "NO") << '\n';
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