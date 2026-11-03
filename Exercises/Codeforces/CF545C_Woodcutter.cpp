#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n), h(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> h[i];
    }

    vector<array<ll, 3>> dp(n);
    dp[0][0] = 0;
    dp[0][1] = 1;
    if (x[0] + h[0] >= x[1]) {
        dp[0][2] = -inf;
    } else {
        dp[0][2] = 1;
    }

    for (int i = 1; i < n; ++i) {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});

        if (x[i] - h[i] <= x[i - 1]) {
            dp[i][1] = -inf;
        } else if (x[i] - h[i] <= x[i - 1] + h[i - 1]) {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        } else {
            dp[i][1] = dp[i][0] + 1;
        }

        if (i + 1 >= n || x[i] + h[i] < x[i + 1]) {
            dp[i][2] = dp[i][0] + 1;
        } else {
            dp[i][2] = -inf;
        }
    }

    // cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;
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
