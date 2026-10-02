#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e4 + 10;
const int M = 1e5 + 10;

struct {
    int to, ne;
} edge[M];
int head[N], cnt;

void addEdge(int u, int v) {
    edge[++cnt] = {v, head[u]};
    head[u] = cnt;
}

int dfn[N], low[N], timer;
int scc[N], sccSize[N], sccCnt;
int top, stk[N];
bool inStack[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    inStack[u] = true;
    stk[++top] = u;

    for (int e = head[u]; e; e = edge[e].ne) {
        int v = edge[e].to;
        if (dfn[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        ++sccCnt;
        while (1) {
            int v = stk[top--];
            inStack[v] = false;
            ++sccSize[sccCnt];
            scc[v] = sccCnt;
            if (v == u) break;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    for (int i = 1; i <= n; ++i) {
        if (dfn[i] == 0) tarjan(i);
    }

    cout << sccCnt << endl;
    vector<bool> vis(sccCnt + 1, false);

    for (int u = 1; u <= n; ++u) {
        int s = scc[u];
        if (vis[s]) continue;
        vis[s] = true;
        for (int v = 1; v <= n; ++v) {
            if (scc[v] == s) cout << v << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}
