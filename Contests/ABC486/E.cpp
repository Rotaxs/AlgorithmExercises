#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct Edge {
    int u, v;
    ll w;
};

void solve() {
    int n, m; cin >> n >> m;
    vector<Edge> e(m);
    for (auto &[u, v, w] : e) cin >> u >> v >> w;

    sort(e.begin(), e.end(), [&](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    vector<ll> dp(n + 1, 0), ndp(n + 1, -1);
    vector<int> vis;

    for (int i = 0; i < m; ) {
        int j = i;
        while (j < m && e[j].w == e[i].w) ++j;
        for (int k = i; k < j; ++k) {
            int u = e[k].u, v = e[k].v;
            ll w = e[k].w;
            if (ndp[u] < 0) vis.push_back(u);
            if (ndp[v] < 0) vis.push_back(v);
            ndp[v] = max(ndp[v], dp[u] + w);
            ndp[u] = max(ndp[u], dp[v] + w);
        }
        for (int x : vis) {
            dp[x] = max(dp[x], ndp[x]);
            ndp[x] = -1;
        }
        vis.clear();
        i = j;
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
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
