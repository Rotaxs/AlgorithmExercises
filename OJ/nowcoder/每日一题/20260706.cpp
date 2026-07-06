#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 510;

struct { int ne, to; } edge[N * N];
int head[N], cnt;
bool vis[N];
int match[N];

void add_edge(int u, int v)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].ne = head[u];
    head[u] = cnt;
}

bool dfs(int u)
{
    for (int e = head[u]; e; e = edge[e].ne)
    {
        int v = edge[e].to;
        if (vis[v]) continue;
        vis[v] = true;
        if (!match[v] || dfs(match[v]))
        {
            match[v] = u;
            return true;
        }
    }
    return false;
}

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (gcd(a[i], b[j]) == 1)
                add_edge(i, j);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof vis);
        if (dfs(i)) ans++;
    }
    cout << (ans == n ? "Bob" : "Alice") << '\n';
    
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