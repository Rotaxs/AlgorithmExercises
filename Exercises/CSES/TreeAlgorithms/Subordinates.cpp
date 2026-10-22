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
    for (int v = 2; v <= n; ++v) {
        int u;
        cin >> u;
        addEdge(u, v);
        addEdge(v, u);
    }

    // dfs

    // vector<int> dp(n + 1, 0);
    // function<void(int, int)> dfs = [&](int u, int fa) {
    //     ++dp[u];
    //     for (int e = head[u]; e; e = edge[e].ne) {
    //         int v = edge[e].to;
    //         if (v == fa) continue;
    //         dfs(v, u);
    //         dp[u] += dp[v];
    //     }
    // };
    // dfs(1, 0);

    // 非递归
    vector<int> order, fa(n + 1);
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

    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            dp[u] += dp[v] + 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dp[i] << ' ';
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
