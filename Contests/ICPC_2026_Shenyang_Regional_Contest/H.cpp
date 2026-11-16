#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> mat(n);
    vector<int> c2r(n), r2c(n), color(n);
    for (int i = 0; i < n; ++i) {
        cin >> mat[i];
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == '.') continue;
            c2r[j] = i;
            r2c[i] = j;
            color[i] = mat[i][j];
        }
    }

    vector<string> ans(n, string(n, '.'));
    vector<bool> occupied(n, false);
    for (int r = 0; r < n; ++r) {
        int c = r2c[r], v = color[r];
        occupied[c] = true;

        int L = c, R = c;
        while (L > 0 && occupied[L - 1]) --L;
        while (R + 1 < n && occupied[R + 1]) ++R;
        for (int j = L; j <= R; ++j) ans[r][j] = v;

        for (int i = r - 1; i >= 0; --i) {
            int p = L;
            while (p < R && ans[i][p] != '.') ++p;
            if (ans[i][p] != '.') break;
            L = R = p;
            while (L - 1 >= 0 && ans[i][L - 1] == '.') --L;
            while (R + 1 <n && ans[i][R + 1] == '.') ++R;
            for (int j = L; j <= R; ++j) ans[i][j] = v;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;


// void solve() {
//     int n; cin >> n;
//     vector<string> g(n);
//     vector<int> c2r(n), r2c(n), color(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> g[i];
//         for (int j = 0; j < n; ++j) {
//             if (g[i][j] != '.') {
//                 color[i] = g[i][j];
//                 r2c[i] = j;
//                 c2r[j] = i;
//             }
//         }
//     }

//     vector<string> ans(n, string(n, '.'));
//     for (int r = 0; r < n; ++r) {
//         int c = r2c[r];
//         int v = color[r];
//         for (int i = r; i < n; ++i) {
//             ans[i][c] = v;
//         }
//         int R, rr = n;
//         for (R = c + 1; R < n; ++R) {
//             if (ans[r][R] != '.') break;
//             rr = min(rr, c2r[R]);
//         }
//         --R; --rr;
//         int L, lr = n;
//         for (L = c - 1; L >= 0; --L) {
//             if (ans[r][L] != '.') break;
//             lr = min(lr, c2r[L]);
//         }
//         ++L; --lr;
//         for (int i = r; i <= lr; ++i) {
//             for (int j = L; j <= c - 1; ++j) {
//                 ans[i][j] = v;
//             }
//         }
//         for (int i = r; i <= rr; ++i) {
//             for (int j = c + 1; j <= R; ++j) {
//                 ans[i][j] = v;
//             }
//         }
//     }

//     for (int i = 0; i < n; ++i) {
//         cout << ans[i] << endl;
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int _ = 1;
//     // cin >> _;
//     while (_--)
//         solve();

//     return 0;
// }
