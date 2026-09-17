#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1510;
const int M = 5e5 + 10;

struct {
    int ne, to, w;
} edge[M];
int head[N], cnt, in[N];

void add_edge(int u, int v, int w) {
    edge[++cnt] = {head[u], v, w};
    head[u] = cnt;
    ++in[v];
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    queue<int> q;
    vector<int> dp(n + 1, -1e9);

    for (int v = 1; v <= n; ++v) {
        if (in[v] == 0) {
            q.push(v);
        }
    }
    dp[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            int w = edge[e].w;
            if (dp[u] != -1e9) {
                dp[v] = max(dp[v], dp[u] + w);
            }
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }

    if (dp[n] == -1e9) {
        cout << -1 << endl;
    } else {
        cout << dp[n] << endl;
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
