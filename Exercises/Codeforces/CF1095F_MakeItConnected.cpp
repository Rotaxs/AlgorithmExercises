#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;

const int N = 2e5 + 10;

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
    vector<ll> a(n + 1);
    ll sum = 0, minn = inf;
    int id = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (a[i] < minn) {
            minn = a[i];
            id = i;
        }
    }

    vector<Edge> edge;
    for (int v = 1; v <= n; ++v) {
        if (v == id) continue;
        edge.push_back({v, id, a[v] + minn});
    }

    for (int i = 1; i <= m; ++i) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        edge.push_back({x, y, w});
    }

    sort(edge.begin(), edge.end());

    DSU dsu(n);
    ll ans = 0;
    int cnt = 0;
    for (auto& [u, v, w] : edge) {
        if (dsu.merge(u, v)) {
            ans += w;
            ++cnt;
        }
        if (cnt == n - 1) break;
    }
    cout << ans << endl;
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
