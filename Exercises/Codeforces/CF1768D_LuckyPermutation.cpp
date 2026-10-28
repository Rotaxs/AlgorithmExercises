#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

int getCircle(const vector<int>& p) {
    int n = p.size() - 1;
    vector<bool> vis(n + 1, false);
    int k = 0;
    for (int u = 1; u <= n; ++u) {
        if (vis[u]) continue;
        ++k;
        int v = u;
        while (!vis[v]) {
            vis[v] = true;
            v = p[v];
        }
    }
    return k;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    int k = getCircle(p);

    vector<int> vis(n + 1, -1);
    int stamp = 0;

    function<bool(int)> dfs = [&](int u) -> bool {
        int v = p[u];
        if (vis[v] == stamp) return false;
        vis[v] = stamp;
        if ((v + 1 <= n && vis[v + 1] == stamp) || (v - 1 >= 1 && vis[v - 1] == stamp)) return true;
        return dfs(v);
    };

    for (int u = 1; u <= n; ++u) {
        if (vis[u] > 0) continue;
        ++stamp;
        if (dfs(u)) {
            cout << n - k - 1 << endl;
            return;
        }
    }

    cout << n - k + 1 << endl;
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
