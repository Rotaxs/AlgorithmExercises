#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);

    int root = 0, rootCnt = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            root = i;
            ++rootCnt;
        }
    }

    vector<int> g[n + 1];
    set<int> used[n + 1];
    for (int u = 1; u <= n; ++u) {
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int v;
            cin >> v;
            g[u].push_back(v);
        }
    }

    if (rootCnt != 1) {
        cout << -1 << endl;
        return;
    }

    vector<int> ans[n + 1];
    vector<bool> vis(n + 1, false);

    queue<int> q;
    vis[root] = true;
    q.push(root);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (a[v] == a[u] + 1 && !vis[v]) {
                q.push(v);
                vis[v] = true;
                ans[u].push_back(v);
                used[u].insert(v);
            }
        }
    }

    for (int u = 1; u <= n; ++u) {
        for (int v : g[u]) {
            if (!used[u].count(v)) {
                ans[u].push_back(v);
            }
        }
    }

    vector<int> dep(n + 1, 0);
    fill(vis.begin(), vis.end(), false);

    function<void(int, int)> dfs = [&](int u, int d) {
        vis[u] = true;
        dep[u] = d;
        for (int v : ans[u]) {
            if (vis[v]) continue;
            dfs(v, d + 1);
        }
    };

    dfs(root, 0);

    if (dep == a) {
        cout << root << endl;
        for (int u = 1; u <= n; ++u) {
            for (int v : ans[u]) {
                cout << v << ' ';
            }
            cout << endl;
        }
    } else {
        cout << -1 << endl;
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
