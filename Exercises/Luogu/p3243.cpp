#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct Edge {
    int ne, to;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edge(m + 1);
    vector<int> head(n + 1, 0), in(n + 1, 0);
    int cnt = 0;

    auto add_edge = [&](int u, int v) {
        edge[++cnt] = {head[u], v};
        ++in[v];
        head[u] = cnt;
    };

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(v, u);
    }

    vector<int> res;

    auto topo = [&]() -> bool {
        priority_queue<int> pq;
        for (int i = 1; i <= n; ++i) {
            if (in[i] == 0) pq.push(i);
        }

        while (!pq.empty()) {
            int u = pq.top();
            res.push_back(u);
            pq.pop();
            for (int e = head[u]; e; e = edge[e].ne) {
                int v = edge[e].to;
                if (--in[v] == 0) {
                    pq.push(v);
                }
            }
        }

        return res.size() == n;
    };

    if (topo()) {
        reverse(res.begin(), res.end());
        for (int x : res) {
            cout << x << ' ';
        }
        cout << endl;
    } else {
        cout << "Impossible!" << endl;
    }
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
