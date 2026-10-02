#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10; // 最大点数
const int M = 5e5 + 10; // 最大边数

struct {
    int to, ne;
} edge[M];
int head[N], cnt;

int dfn[N], low[N], timer;
int stk[N], top;
bool inStack[N];
int scc[N], sccCnt; // scc[u] u 所属的强连通分量编号
int sccSize[N];     // 各强连通分量的点数

void addEdge(int u, int v) {
    edge[++cnt] = {v, head[u]};
    head[u] = cnt;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    stk[++top] = u;
    inStack[u] = true;

    for (int e = head[u]; e; e = edge[e].ne) {
        int v = edge[e].to;
        if (!dfn[v]) { // 树边
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) { // 回边
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u]) { // 封装口袋
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
        if (!dfn[u]) tarjan(u);
    }
}