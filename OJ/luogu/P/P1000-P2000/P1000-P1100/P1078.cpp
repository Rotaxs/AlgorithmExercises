#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 110;
const int M = 10010;
const int inf = 0x3f3f3f3f;

struct { int to, ne, w; } edge[M];
int head[N], cnt;
int c[N], g[N][N];
int dist[N];

void add_edge(int u, int v, int w)
{
    edge[++cnt] = {v, head[u], w};
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
        for (int e = head[u];)
    }
}

void solve()
{
    int n, k, m, s, t; cin >> n >> k >> m >> s >> t;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= k; j++)
            cin >> g[i][j];
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

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