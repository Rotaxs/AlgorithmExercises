#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 110;
vector<int> g[N];
int in[N];

void solve() {
    int n;
    cin >> n;
    for (int u = 1; u <= n;) {
        int v;
        cin >> v;
        if (v == 0) {
            ++u;
            continue;
        }
        ++in[v];
        g[u].push_back(v);
    }

    auto topo = [&](void) {
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (in[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << ' ';
            for (int v : g[u]) {
                if (--in[v] == 0) {
                    q.push(v);
                }
            }
        }
    };

    topo();
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
