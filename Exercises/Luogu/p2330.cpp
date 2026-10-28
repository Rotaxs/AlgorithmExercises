#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n + 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        fa[x] = y;
        return true;
    }
};

struct Edge {
    int u, v;
    ll w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edge(m);
    for (auto& [u, v, w] : edge) {
        cin >> u >> v >> w;
    }

    sort(edge.begin(), edge.end());
    DSU dsu(n);
    ll ans = 0;
    int cnt = 0;
    for (auto [u, v, w] : edge) {
        if (dsu.merge(u, v)) {
            ++cnt;
            ans = max(ans, w);
        }
        if (cnt == n - 1) break;
    }

    cout << cnt << ' ' << ans << endl;
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
