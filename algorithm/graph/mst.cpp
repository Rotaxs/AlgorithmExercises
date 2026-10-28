#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU {
    vector<int> fa, sz;
    DSU(int n) : fa(n + 1), sz(n + 1, 0) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
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

bool mst(int n, const vector<Edge>& edge) {
    sort(edge.begin(), edge.end());
    DSU dsu(n);
    ll ans = 0;
    int cnt = 0;
    for (auto [u, v, w] : edge) {
        if (dsu.merge(u, v)) {
            ans += w;
            ++cnt;
        }
        if (cnt == n - 1) break;
    }
    return cnt == n - 1;
}

int main() {

    return 0;
}