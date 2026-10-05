#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1010;
const int M = 6010;

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
    cnt = 0;
    memset(head, 0, sizeof head);
    timer = top = sccCnt = 0;
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(scc, 0, sizeof scc);
    memset(sccSize, 0, sizeof sccSize);
    memset(inStack, 0, sizeof inStack);

    int n, m;
    cin >> n >> m;

    vector<int> a(m + 1), b(m + 1);

    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i];
        addEdge(a[i], b[i]);
    }

    for (int u = 1; u <= n; ++u) {
        if (!dfn[u]) tarjan(u);
    }

    cnt = 0;
    memset(head, 0, sizeof head);
    vector<int> in(m + 1, 0);

    for (int i = 1; i <= m; ++i) {
        int scc1 = scc[a[i]];
        int scc2 = scc[b[i]];
        if (scc1 != scc2) {
            addEdge(scc1, scc2);
            ++in[scc2];
        }
    }

    queue<int> q;

    for (int i = 1; i <= sccCnt; ++i) {
        if (in[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        if ((int)q.size() > 1) {
            cout << "No" << endl;
            return;
        }
        q.pop();
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << "Yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}

// ==== 暴力 ======

// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;

// const int N = 1010;
// const int M = 6010;

// struct {
//     int to, ne;
// } edge[M];
// int head[N], cnt;

// void addEdge(int u, int v) {
//     edge[++cnt] = {v, head[u]};
//     head[u] = cnt;
// }

// void solve() {
//     cnt = 0;
//     memset(head, 0, sizeof head);

//     int n, m;
//     cin >> n >> m;

//     // vector<int> u(m + 1), v(m + 1);

//     for (int i = 1; i <= m; ++i) {
//         // cin >> u[i] >> v[i];
//         // addEdge(u[i], v[i]);
//         int u, v;
//         cin >> u >> v;
//         addEdge(u, v);
//     }

//     vector<vector<bool>> connect(n + 1, vector<bool>(n + 1, false));
//     vector<bool> vis(n + 1, false);

//     function<void(int, int)> dfs = [&](int u, int s) {
//         for (int e = head[u]; e; e = edge[e].ne) {
//             int v = edge[e].to;
//             if (vis[v]) continue;
//             vis[v] = true;
//             connect[s][v] = true;
//             connect[v][s] = true;
//             dfs(v, s);
//         }
//     };

//     for (int u = 1; u <= n; ++u) {
//         vis[u] = true;
//         dfs(u, u);
//         fill(vis.begin(), vis.end(), false);
//     }

//     bool ok = true;

//     for (int u = 1; u <= n; ++u) {
//         for (int v = 1; v <= n; ++v) {
//             if (u == v) continue;
//             if (!connect[u][v]) {
//                 ok = false;
//                 break;
//             }
//         }
//         if (!ok) break;
//     }

//     cout << (ok ? "Yes" : "No") << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int _ = 1;
//     cin >> _;
//     while (_--)
//         solve();

//     return 0;
// }
