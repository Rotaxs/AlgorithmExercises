#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 1e4 + 10;
const int M = 1e5 + 10;

struct edge { int to, ne; } edge[M * 2];
int head[N], cnt;
int color[N];

void addEdge(int u, int v)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].ne = head[u];
    head[u] = cnt;
}

int white, black;

bool dfs(int u, int c)
{
    color[u] = c;
    if (c == 0) white++;
    else black++;
    for (int e = head[u]; e; e = edge[e].ne)
    {
        int v = edge[e].to;
        if (color[u] == color[v]) return false;
        // 这里不能这样写，因为如果 dfs 返回 true 也会终止循环，但是无法保证与 u 向量的其他节点不会返回 false
        // 因此不能在这里不确定 dfs 是 true 还是 false 的情况下返回
        // if (color[v] == -1) return dfs(v, !color[u]);
        if (color[v] == -1 && !dfs(v, !color[u])) return false;
    }
    return true;
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    memset(color, -1, sizeof color);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] != -1) continue;
        white = black = 0;
        if (!dfs(i, 0))
        {
            cout << "Impossible\n";
            return;
        }
        ans += min(white, black);
    }
    cout << ans << endl;
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