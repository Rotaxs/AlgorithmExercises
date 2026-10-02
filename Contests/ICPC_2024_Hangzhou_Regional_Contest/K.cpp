#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> pos(n + 1, vector<int>());
    for (int i = 1; i <= n * m; ++i) {
        int x; cin >> x;
        int a = (x - 1) / m + 1;
        pos[a].push_back(i);
    }
    if (k >= m) {
        cout << m << endl;
        return;
    }
    int ans = 1e9;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, max(pos[i][m - k - 1], m));
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
