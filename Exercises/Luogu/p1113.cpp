#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 10010;

vector<int> g[N];
int in[N];

void solve() {
    int n;
    cin >> n;

    vector<int> cost(n + 1);

    for (int i = 1; i <= n; ++i) {
        int u, c;
        cin >> u >> c;
        cost[u] = c;
        int v;
        while (1) {
            cin >> v;
            if (v == 0) break;
            g[u].push_back(v);
            ++in[v];
        }
    }

    queue<int> q;
    vector<int> dp(n + 1, 0);

    for (int v = 1; v <= n; ++v) {
        if (in[v] == 0) {
            q.push(v);
            dp[v] = cost[v];
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            dp[v] = max(dp[v], dp[u] + cost[v]);
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i]);
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
