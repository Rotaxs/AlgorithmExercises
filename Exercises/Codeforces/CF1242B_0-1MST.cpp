#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> e[n + 1];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    set<int> unvis;
    for (int u = 1; u <= n; ++u) {
        unvis.insert(u);
    }

    queue<int> q;
    int cnt = 0;
    vector<int> mark(n + 1, 0);

    while (!unvis.empty()) {
        int s = *unvis.begin();
        unvis.erase(s);
        q.push(s);
        ++cnt;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : e[u]) {
                mark[v] = u;
            }

            for (auto it = unvis.begin(); it != unvis.end();) {
                int v = *it;
                if (mark[v] == u) {
                    ++it;
                } else {
                    q.push(v);
                    it = unvis.erase(it);
                }
            }
        }
    }

    cout << cnt - 1 << endl;
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
