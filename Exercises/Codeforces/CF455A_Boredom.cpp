#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = array<ll, 2>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    vector<int> cnt(mx + 1, 0);
    for (int i = 0; i < n; ++i) {
        ++cnt[a[i]];
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int sz = a.size();
    vector<pll> dp(sz);

    dp[0][0] = 0;
    dp[0][1] = 1ll * cnt[a[0]] * a[0];
    for (int i = 1; i < sz; ++i) {
        if (a[i] - a[i - 1] > 1) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i][0] + 1ll * cnt[a[i]] * a[i];
        } else {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + 1ll * cnt[a[i]] * a[i];
        }
    }

    cout << max(dp[sz - 1][0], dp[sz - 1][1]) << endl;
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
