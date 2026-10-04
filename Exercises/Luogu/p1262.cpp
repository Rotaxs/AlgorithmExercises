#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 3010;
const int M = 8010;
const int inf = 2e9;

struct {
    int to, ne;
} edge[M];
int head[N], cnt;

int dfn[N], low[N], timer;
int stk[N], top;
bool inStack[N];
int scc[N], sccCnt; // scc[u] u 所属的强连通分量编号
int sccSize[N];     // 各强连通分量的点数
int cost[N], minCost[N];

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
        minCost[sccCnt] = inf;
        while (1) {
            int v = stk[top--];
            inStack[v] = false;
            scc[v] = sccCnt;
            ++sccSize[sccCnt];
            minCost[sccCnt] = min(minCost[sccCnt], cost[v]);
            if (v == u) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int p;
    cin >> p;

    for (int i = 1; i <= n; ++i) {
        cost[i] = inf;
    }

    for (int i = 1; i <= p; ++i) {
        int x, c;
        cin >> x >> c;
        cost[x] = c;
    }

    int r;
    cin >> r;

    vector<int> u(r), v(r);
    for (int i = 0; i < r; ++i) {
        cin >> u[i] >> v[i];
        addEdge(u[i], v[i]);
    }

    for (int u = 1; u <= n; ++u) {
        if (cost[u] != inf && !dfn[u]) tarjan(u);
    }

    for (int u = 1; u <= n; ++u) {
        if (scc[u] == 0) {
            cout << "NO" << endl;
            cout << u << endl;
            return;
        }
    }

    vector<int> in(n + 1);
    for (int i = 0; i < r; ++i) {
        int scc1 = scc[u[i]];
        int scc2 = scc[v[i]];
        if (scc1 != scc2) {
            ++in[scc2];
        }
    }

    int ans = 0;
    for (int i = 1; i <= sccCnt; ++i) {
        if (in[i] == 0) {
            ans += minCost[i];
        }
    }
    cout << "YES" << endl;
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
