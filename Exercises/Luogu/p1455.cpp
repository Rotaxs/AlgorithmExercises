// ====== Tarjan =======

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e4 + 10; // 最大点数
const int M = 1e4 + 10; // 最大边数

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
    int n, m, w;
    cin >> n >> m >> w;

    vector<int> cost(n + 1), val(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i] >> val[i];
    }

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) tarjan(i);
    }

    vector<int> costReal(sccCnt + 1, 0), valReal(sccCnt + 1, 0);
    for (int i = 1; i <= n; ++i) {
        costReal[scc[i]] += cost[i];
        valReal[scc[i]] += val[i];
    }

    vector<int> dp(w + 1, 0);
    for (int i = 1; i <= sccCnt; ++i) {
        for (int j = w; j >= costReal[i]; --j) {
            dp[j] = max(dp[j], dp[j - costReal[i]] + valReal[i]);
        }
    }

    cout << dp[w] << endl;
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

// ======== 并查集 ===========

// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;

// const int N = 1e4 + 10;

// int fa[N], cost[N], val[N], dp[N];

// void init() {
//     for (int i = 0; i < N; ++i) {
//         fa[i] = i;
//     }
// }

// int find(int x) {
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }

// void unite(int x, int y) {
//     int rx = find(x), ry = find(y);
//     if (rx == ry) {
//         return;
//     }
//     fa[ry] = rx;
//     cost[rx] += cost[ry];
//     val[rx] += val[ry];
// }

// void solve() {
//     int n, m, w;
//     cin >> n >> m >> w;

//     for (int i = 1; i <= n; ++i) {
//         cin >> cost[i] >> val[i];
//     }

//     init();

//     for (int i = 0; i < m; ++i) {
//         int u, v;
//         cin >> u >> v;
//         unite(u, v);
//     }

//     for (int i = 1; i <= n; ++i) {
//         if (fa[i] != i) continue;
//         for (int j = w; j >= cost[i]; --j) {
//             dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
//         }
//     }

//     cout << dp[w] << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int _ = 1;
//     // cin >> _;
//     while (_--)
//         solve();

//     return 0;
// }
