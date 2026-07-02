#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
const int M = 4e6 + 10;
const int MOD = 100003;
const int inf = 0x3f3f3f3f;

struct { int to, ne, w; } edge[M];
int head[N], cnt;
int dist[N], ans[N];
bool vis[N];

void add_edge(int u, int v, int w)
{
    edge[++cnt] = {v, head[u], w};
    head[u] = cnt;
}

void dijkstra(int s, int n)
{
    for (int i = 1; i <= n; i++) dist[i] = inf;
    dist[1] = 0; ans[1] = 1;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, s});
    while (pq.size())
    {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int e = head[u]; e; e = edge[e].ne)
        {
            int v = edge[e].to, w = edge[e].w;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                ans[v] = ans[u];
                pq.push({dist[v], v});  
            }
            else if (dist[v] == dist[u] + w)
            {
                ans[v] = (ans[v] + ans[u]) % MOD;
            }
        }
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        add_edge(u, v, 1);
        add_edge(v, u, 1);
    }
    dijkstra(1, n);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
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