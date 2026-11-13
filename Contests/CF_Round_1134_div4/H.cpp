#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> e[n + 1];
    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> order, fa(n + 1);
    order.push_back(1);
    fa[1] = 0;
    for (int i = 0; i < n; ++i) {
        int u = order[i];
        for (int v : e[u]) {
            if (fa[u] == v) continue;
            order.push_back(v);
            fa[v] = u;
        }
    }

    vector<int> sz(n + 1, 1);
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        for (int v : e[u]) {
            if (v == fa[u]) continue;
            sz[u] += sz[v];
        }
    }

    vector<bool> vis(n + 1, false);
    vis[1] = true;

    int m1 = -1, m2 = -1;

    for (int v : e[1]) {
        if (vis[v]) continue;
        if (m1 == -1) {
            m1 = v;
            continue;
        }
        if (sz[v] >= sz[m1]) {
            m2 = m1;
            m1 = v;
        } else if (m2 == -1 || sz[v] > sz[m2]) {
            m2 = v;
        }
    }

    vis[m1] = true;
    if (m2 != -1) {
        vis[m2] = true;
    }

    int len = 1;
    for (int i = 0; i < n; ++i) {
        int u = order[i];
        if (u == 1) continue;
        if ((int)e[u].size() == 1) continue;
        if (!vis[u]) continue;
        int mx = -1;
        for (int v : e[u]) {
            if (v == fa[u]) continue;
            if (mx == -1 || sz[v] > sz[mx]) {
                mx = v;
            }
        }
        if (mx != -1) {
            vis[mx] = true;
            ++len;
        }
    }

    int loss = 0;
    for (int i = 0; i < n; ++i) {
        int u = order[i];
        for (int v : e[u]) {
            if (v == fa[u] || vis[v]) continue;
            if (sz[v] > loss) {
                loss = sz[v];
            }
        }
    }

    cout << n - loss << endl;
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
