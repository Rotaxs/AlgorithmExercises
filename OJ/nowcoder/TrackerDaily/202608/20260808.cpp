#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

const int N = 2e5 + 10;

struct { int to, ne; } edge[N << 1];
int head[N], cnt;

void addEdge(int u, int v) {
    ++cnt;
    edge[cnt].to = v;
    edge[cnt].ne = head[u];
    head[u] = cnt;
}

void solve()
{
    int n; cin >> n;
    vector<bool> black(n + 1);

    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    int cnt = 0;
    black[1] = true;

    function<void(int, int)> dfs = [&](int u, int fa) {
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa) continue;
            black[v] = !black[u];
            dfs(v, u);
        }
    };

    dfs(1, 0);

    for (int i = 1; i <= n; ++i) {
        if (black[i]) ++cnt;
    }

    cout << 1LL * cnt * (cnt + 1) / 2 << endl;

    ::cnt = 0;
    for (int i = 1; i <= n; ++i) head[i] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}