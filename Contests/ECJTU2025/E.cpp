#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 10));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[j][i];
        }
    }

    auto check = [&]() -> bool {
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] > mat[r + 1][c] || mat[r][c] > mat[r][c + 1]) return false;
            }
        }
        return true;
    };

    for (int r = 0; r < n; ++r) {
        sort(mat[r].begin(), mat[r].begin() + n);
    }

    cout << (check() ? "Yes" : "No") << endl;
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
