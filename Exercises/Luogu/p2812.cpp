#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e4 + 10; // 最大点数
const int M = 5e4 + 10; // 最大边数

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
    int n;
    cin >> n;
    vector<int> out(n + 1), in(n + 1);

    for (int u = 1; u <= n; ++u) {
        int v;
        while (1) {
            cin >> v;
            if (v == 0) break;
            addEdge(u, v);
        }
    }

    for (int u = 1; u <= n; ++u) {
        if (dfn[u] == 0) tarjan(u);
    }

    for (int u = 1; u <= n; ++u) {
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            int scc1 = scc[u];
            int scc2 = scc[v];
            if (scc1 != scc2) {
                ++in[scc2];
                ++out[scc1];
            }
        }
    }

    int inCnt = 0, outCnt = 0;
    for (int i = 1; i <= sccCnt; ++i) {
        if (in[i] == 0) ++inCnt;
        if (out[i] == 0) ++outCnt;
    }

    cout << inCnt << endl;
    cout << (sccCnt == 1 ? 0 : max(inCnt, outCnt)) << endl;
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
