#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 10;
const int M = 1e6 + 10;

struct { int to, ne; } edge[M];
int head[N], cnt;
bool vis[N];

void add_edge(int u, int v)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].ne = head[u];
    head[u] = cnt;
}

void dfs(int u)
{
    if (u == 0) return;
    if (vis[u]) return;
    vis[u] = true;
    cout << u << ' ';
    vector<int> nxt;
    for (int e = head[u]; e != 0; e = edge[e].ne)
        nxt.push_back(edge[e].to);
    sort(nxt.begin(), nxt.end());
    for (int v : nxt)
        dfs(v); 
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    
    while (!q.empty())
    {
        int f = q.front(); q.pop();
        if (vis[f]) continue;
        vis[f] = true;
        cout << f << ' ';
        vector<int> nxt;
        for (int e = head[f]; e != 0; e = edge[e].ne)
            nxt.push_back(edge[e].to);
        sort(nxt.begin(), nxt.end());
        for (int v : nxt) q.push(v);
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        add_edge(u, v);
    }
    dfs(1);
    for (int i = 0; i <= n; i++)    
        vis[i] = false;
    cout << '\n';
    bfs(1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    
    return 0;
}