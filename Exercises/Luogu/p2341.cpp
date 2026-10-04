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
int inStack[N];

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
            ++sccSize[sccCnt];
            scc[v] = sccCnt;
            if (v == u) break;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> u(m), v(m), out(n + 1);

    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i];
        addEdge(u[i], v[i]);
    }

    for (int i = 1; i <= n; ++i) {
        if (dfn[i] == 0) tarjan(i);
    }

    for (int i = 0; i < m; ++i) {
        int scc1 = scc[u[i]];
        int scc2 = scc[v[i]];
        if (scc1 != scc2) {
            ++out[scc1];
        }
    }

    int ans = 0, nums = 0;
    for (int i = 1; i <= sccCnt; ++i) {
        if (out[i] == 0) {
            if (++nums > 1) {
                ans = 0;
                break;
            }
            ans = sccSize[i];
        }
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
