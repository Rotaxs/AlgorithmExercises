#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 5e3 + 10;
const int M = 5e4 + 10;

struct {
    int to, ne;
} edge[M];
int head[M], cnt;

void addEdge(int u, int v) {
    edge[++cnt] = {v, head[u]};
    head[u] = cnt;
}

int dfn[N], low[N], timer;
int scc[N], sccSize[N], sccCnt, maxSize;
int stk[N], top;
bool inStack[N];
vector<int> sccs[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    stk[++top] = u;
    inStack[u] = true;

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
            scc[v] = sccCnt;
            ++sccSize[sccCnt];
            sccs[sccCnt].push_back(v);
            maxSize = max(sccSize[sccCnt], maxSize);
            if (v == u) break;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        addEdge(u, v);
        if (t == 2) {
            addEdge(v, u);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dfn[i] == 0) tarjan(i);
    }

    int idx = 0;
    for (int u = 1; u <= n; ++u) {
        if (sccSize[scc[u]] == maxSize) {
            idx = scc[u];
            break;
        }
    }

    sort(sccs[idx].begin(), sccs[idx].end());

    cout << maxSize << endl;
    for (int u : sccs[idx]) {
        cout << u << ' ';
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
