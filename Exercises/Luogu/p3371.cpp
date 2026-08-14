#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int M = 5e5 + 10;
const int N = 1e4 + 10;
const int inf = (ll)(1 << 31) - 1;

struct { int ne, to , w; } edge[M];
int head[N], cnt, dist[N];
bool vis[N];

void add_edge(int u, int v, int w)
{
    edge[++cnt] = {head[u], v, w};
    head[u] = cnt;
}

void dijkstra(int s, int n)
{
    for (int i = 1; i <= n; i++) dist[i] = inf;
    dist[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, s});
    while (pq.size())
    {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int e = head[u]; e; e = edge[e].ne)
        {
            if (dist[u] == inf) continue;
            int v = edge[e].to, w = edge[e].w;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve()
{
    int n, m, s; cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    dijkstra(s, n);
    for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
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