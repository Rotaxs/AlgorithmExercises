#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> mat(n);

    string t1 = string(m, 'x'), t2 = string(n, 'x');

    for (int i = 0; i < n; ++i) cin >> mat[i];

    for (int i = 0; i < n; ++i) {
        if (mat[i] == t1) {
            cout << "Faucet " << i + 1 << endl;
            return;
        }
    }

    for (int j = 0; j < m; ++j) {
        string col;
        for (int i = 0; i < n; ++i) {
            col += mat[i][j];
        }
        if (col == t2) {
            cout << "Drain " << j + 1 << endl;
            return;
        }
    }
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
