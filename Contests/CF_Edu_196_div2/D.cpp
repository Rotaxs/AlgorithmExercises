#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct DSU {
    int n;
    vector<int> fa;
    DSU(int n) : n(n + 1), fa(n + 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    void merge(int x, int y) {
        int rootx = find(x), rooty = find(y);
        if (rootx == rooty) return;
        fa[rooty] = rootx;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> edges(n - 1);
    for (auto& [u, v] : edges) {
        cin >> u >> v;
    }

    if (n % 2 == 0) {
        cout << n + 1 << endl;
        return;
    }

    auto check = [&](int k, int x) -> bool {
        DSU dsu(n);
        for (auto [u, v] : edges) {
            if (u == x || v == x) continue;
            dsu.merge(u, v);
        }
        for (int u = 1; u <= n; ++u) {
            int v = k - u;
            if (v < 1 || v > n || u >= v) continue;
            if (dsu.find(u) != dsu.find(v)) {
                return true;
            }
        }
        return false;
    };

    if (check(n, n)) {
        cout << n << endl;
    } else if (check(n + 1, (n + 1) / 2)) {
        cout << n + 1 << endl;
    } else if (check(n + 2, 1)) {
        cout << n + 2 << endl;
    } else {
        cout << n + 1 << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}
