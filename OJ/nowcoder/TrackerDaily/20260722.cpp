#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

int fa[N];
bool marked[N], vis[N];
vector<int> e[N];

void init(int n)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int x)
{
    return (fa[x] == x ? x : fa[x] = find(fa[x]));
}

void unite(int x, int y)
{
    int rx = find(x), ry = find(y);
    if (rx == ry) return;
    fa[ry] = rx;
}

int dfs(int u)
{
    if (!marked[u])
        return 1;
    int res = 0;
    vis[u] = true;
    for (int &v : e[u])
    {
        if (vis[v]) continue;
        res += dfs(v);
    }
    return res;
}

void solve()
{
    int n, k; cin >> n >> k;
    init(n);
    while (k--)
    {
        int a; cin >> a;
        marked[a] = true;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        if (marked[u] && marked[v]) unite(u, v);
    }
    int cnt = 0, ans = 1;
    for (int i = 1; i <= n; i++)
    {
        int linked;
        if (marked[i] && fa[i] == i) 
        {
            cnt++;
            linked = dfs(i);
            ans = (1ll * ans * linked) % MOD;
        }
    }
    cout << cnt << ' ' << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    // cin >> _;
    while (_--) solve();
    
    return 0;
}