#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e4 + 10;
const int M = 5e4 + 10;

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
int stk[N], top;
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

    if (low[u] == dfn[u]) {
        ++sccCnt;
        while (1) {
            int v = stk[top--];
            inStack[v] = false;
            scc[v] = sccCnt;
            ++sccSize[sccCnt];
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

    for (int u = 1; u <= n; ++u) {
        if (dfn[u] == 0) tarjan(u);
    }

    int ans = 0;

    for (int i = 1; i <= sccCnt; ++i) {
        if (sccSize[i] > 1) ++ans;
    }

    cout << ans << endl;
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
