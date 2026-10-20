#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;
const int inf = 1e9;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    // string t;
    // t.reserve(2 * n + 1);
    // t += '#';
    // for (char c : s) {
    //     t += c;
    //     t += '#';
    // }
    // int m = t.size();
    // int ans = 1e9;

    // function<int(int, int, int)> dfs = [&](int i, int l, int r) -> int {
    //     if (l < 0 || r >= m) {
    //         return 0;
    //     }
    //     if (t[l] != t[r]) {
    //         int a1 = dfs(i, l - 1, r + 1);
    //         int a2 = dfs(i, l - 1, r);
    //         int a3 = dfs(i, l, r + 1);
    //     }

    //     return
    // };

    vector<vector<int>> f(n, vector<int>(n, inf));

    for (int i = 0; i < n; ++i) {
        f[i][i] = 0;
        if (i + 1 < n) f[i + 1][i] = 0;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            f[i][j] = min(f[i][j - 1], f[i + 1][j]) + 1;
            if (s[i] == s[j]) {
                f[i][j] = min(f[i][j], f[i + 1][j - 1]);
            } else {
                f[i][j] = min(f[i][j], f[i + 1][j - 1] + 1);
            }
        }
    }

    cout << f[0][n - 1] << endl;
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
