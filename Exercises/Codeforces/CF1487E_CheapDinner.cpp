#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 1e18;

void solve() {
    array<int, 4> n;
    for (int& x : n) {
        cin >> x;
    }

    array<vector<ll>, 4> cost, dp;
    for (int i = 0; i < 4; ++i) {
        cost[i].resize(n[i]);
        for (ll& x : cost[i]) {
            cin >> x;
        }
    }

    array<vector<vector<int>>, 3> ban;
    for (int i = 0; i < 3; ++i) {
        int m;
        cin >> m;
        ban[i].resize(n[i + 1]);
        while (m--) {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            ban[i][y].push_back(x);
        }
    }

    dp[0] = cost[0];
    for (int i = 1; i < 4; ++i) {
        vector<int> order(n[i - 1]);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int x, int y) { return dp[i - 1][x] < dp[i - 1][y]; });

        dp[i].assign(n[i], inf);
        vector<bool> mark(n[i - 1], false);

        for (int j = 0; j < n[i]; ++j) {
            for (int w : ban[i - 1][j]) {
                mark[w] = true;
            }

            for (int w : order) {
                if (dp[i - 1][w] == inf) break;
                if (mark[w]) continue;
                dp[i][j] = cost[i][j] + dp[i - 1][w];
                break;
            }

            for (int w : ban[i - 1][j]) {
                mark[w] = false;
            }
        }
    }

    ll ans = *min_element(dp[3].begin(), dp[3].end());
    cout << (ans == inf ? -1 : ans) << endl;
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
