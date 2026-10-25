#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 5e5 + 10;

struct {
    int ne, to;
} edge[N << 1];
int head[N], cnt;

void addEdge(int u, int v) {
    edge[++cnt] = {head[u], v};
    head[u] = cnt;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        head[i] = 0;

    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    vector<int> d(n + 1, -1);
    queue<int> q;
    q.push(n);
    d[n] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == 1) continue;
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (d[v] >= 0) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }

    int ans = d[1];
    while (m--) {
        int v;
        cin >> v;
        ans = max(ans, d[v] + 1);
    }

    cout << ans << endl;
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
