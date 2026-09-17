#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e4 + 10;
const int M = 5e4 + 10;
const int MOD = 10000;

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
    int n, m, s, e, t;
    cin >> n >> m >> s >> e >> t;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    vector<int> cnt(n + 1, 0);
    vector<ll> sum(n + 1, 0);
    cnt[s] = 1;
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            int w = edge[e].w;
            if (--in[v] == 0) {
                q.push(v);
            }
            cnt[v] = (cnt[v] + cnt[u]) % MOD;
            sum[v] = (sum[v] + sum[u] + 1ll * w * cnt[u]) % MOD;
        }
    }

    int ans = (sum[e] + 1ll * (cnt[e] - 1) * t % MOD) % MOD;

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
