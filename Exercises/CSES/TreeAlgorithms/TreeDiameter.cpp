#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 10;

struct {
    int ne, to;
} edge[N << 1];
int head[N], cnt;

void addEdge(int u, int v) {
    edge[++cnt] = {head[u], v};
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

    vector<int> order, fa(n + 1);
    order.reserve(n);
    fa[1] = 0;
    order.push_back(1);

    for (int i = 0; i < (int)order.size(); ++i) {
        int u = order[i];
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            fa[v] = u;
            order.push_back(v);
        }
    }

    vector<int> dp(n + 1);
    int ans = 0;

    for (int i = n - 1; i >= 0; --i) {
        int mx1 = 0, mx2 = 0;
        int u = order[i];
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            int len = dp[v] + 1;
            if (len >= mx1) {
                mx2 = mx1;
                mx1 = len;
            } else if (len > mx2) {
                mx2 = len;
            }
        }
        ans = max(ans, mx1 + mx2);
        dp[u] = mx1;
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
