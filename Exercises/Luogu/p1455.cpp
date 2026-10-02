#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e4 + 10;

int fa[N], cost[N], val[N], dp[N];

void init() {
    for (int i = 0; i < N; ++i) {
        fa[i] = i;
    }
}

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx == ry) {
        return;
    }
    fa[ry] = rx;
    cost[rx] += cost[ry];
    val[rx] += val[ry];
}

void solve() {
    int n, m, w;
    cin >> n >> m >> w;

    for (int i = 1; i <= n; ++i) {
        cin >> cost[i] >> val[i];
    }

    init();

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        unite(u, v);
    }

    for (int i = 1; i <= n; ++i) {
        if (fa[i] != i) continue;
        for (int j = w; j >= cost[i]; --j) {
            dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
        }
    }

    cout << dp[w] << endl;
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
