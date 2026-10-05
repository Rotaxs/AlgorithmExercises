#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 8010;
const int M = 24010;

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
    stk[++top] = u;
    inStack[u] = true;

    for (int e = head[u]; e; e = edge[e].ne) {
        int v = edge[e].to;
        if (!dfn[v]) {
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
            if (v == u) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    int id = 0;
    unordered_map<string, int> ids;

    vector<int> U, V;

    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        ids[a] = ++id;
        U.push_back(id);
        ids[b] = ++id;
        V.push_back(id);
        addEdge(U[i], V[i]);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        addEdge(ids[b], ids[a]);
    }

    for (int i = 1; i <= id; ++i) {
        if (!dfn[i]) tarjan(i);
    }

    for (int i = 0; i < n; ++i) {
        if (scc[U[i]] == scc[V[i]]) {
            cout << "Unsafe" << endl;
        } else {
            cout << "Safe" << endl;
        }
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
