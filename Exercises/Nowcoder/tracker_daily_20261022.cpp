#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 5e4 + 10;
const int M = 5e4 + 10;

struct {
    int ne, to;
} edge[M << 1];
int head[N], cnt;

void addEdge(int u, int v) {
    edge[++cnt] = {head[u], v};
    head[u] = cnt;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    vector<int> order, fa(n + 1, 0);
    order.reserve(n);
    fa[1] = 0;
    order.push_back(1);

    for (int i = 0; i < (int)order.size(); ++i) {
        int u = order[i];
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            fa[v] = u;
            order.push_back(v);
        }
    }

    vector<ll> dist(n + 1, 0);
    vector<int> sz(n + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        ++sz[u];
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            sz[u] += sz[v];
            dist[u] += dist[v] + sz[v];
        }
    }

    vector<ll> ans(n + 1, 0);
    ans[1] = dist[1];
    ll minn = ans[1];
    for (int i = 0; i < n; ++i) {
        int u = order[i];
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            ans[v] = ans[u] + n - 2 * sz[v];
            minn = min(minn, ans[v]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (ans[i] == minn) {
            cout << i << ' ';
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
