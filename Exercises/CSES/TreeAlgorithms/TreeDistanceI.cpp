#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 10;

struct {
    int to, ne;
} edge[N << 1];
int head[N], cnt;

void addEdge(int u, int v) {
    edge[++cnt] = {v, head[u]};
    head[u] = cnt;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    vector<int> order, fa(n + 1, 0);
    order.reserve(n);
    order.push_back(1);
    fa[1] = 0;

    for (int i = 0; i < (int)order.size(); ++i) {
        int u = order[i];
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            order.push_back(v);
            fa[v] = u;
        }
    }

    vector<int> down(n + 1, 0), up(n + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            down[u] = max(down[u], down[v] + 1);
        }
    }

    for (int u : order) {
        int mx1 = 0, mx2 = 0, id = 0;
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            int d = down[v] + 1;
            if (d >= mx1) {
                mx2 = mx1;
                mx1 = d;
                id = v;
            } else if (d > mx2) {
                mx2 = d;
            }
        }
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            int best = (v == id ? mx2 : mx1);
            up[v] = 1 + max(up[u], best);
        }
    }

    for (int u = 1; u <= n; ++u) {
        cout << max(down[u], up[u]) << ' ';
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
