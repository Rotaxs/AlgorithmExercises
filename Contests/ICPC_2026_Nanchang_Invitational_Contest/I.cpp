#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 1e9 + 10;

void solve() {
    int l, d; cin >> l >> d;
    array<ll, 3> t; cin >> t[0] >> t[1] >> t[2];
    string s; cin >> s;
    s = ' ' + s;
    vector<vector<ll>> dp(l + 1, vector<ll>(4, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= l; ++i) {
        int cost = t[s[i] - '0'];        
        for (int c = 0; c <= 3; ++c) {
            dp[i][c] = dp[i - 1][c] + cost;
            if (c >= 1 && i >= d) dp[i][c] = min(dp[i][c], dp[i - d][c - 1]);
        }
    }
    for (int c = 1; c <= 3; ++c) {
        for (int i = 0; i <= d - 1; ++i) {
            dp[l][c] = min(dp[l][c], dp[l - d + i][c - 1]);
        }
    }
    cout << *min_element(dp[l].begin(), dp[l].end()) << endl;
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
