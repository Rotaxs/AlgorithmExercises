#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 10;
const ll inf = 1e18;

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

    vector<array<ll, 2>> f(n + 1, {0, 0});

    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        ll p = -inf;
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            f[u][0] += max(f[v][0], f[v][1]);
            p = max(p, 1 + f[v][0] - max(f[v][0], f[v][1]));
        }
        f[u][1] = f[u][0] + p;
    }

    cout << max(f[1][0], f[1][1]) << endl;
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
