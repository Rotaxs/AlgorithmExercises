#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

// struct Line {
//     int x, y;
//     ll v;
// };

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     vector<Line> lines(m + 1);
//     for (int i = 1; i <= m; ++i) {
//         cin >> lines[i].x >> lines[i].y >> lines[i].v;
//     }

//     ll ans1 = 0;
//     int curCol = lines[1].x;
//     for (int i = 1; i <= m; ++i) {
//         curCol = (curCol == lines[i].x ? lines[i].y : lines[i].x);
//         ans1 += lines[i].v;
//         while (i + 1 <= m && curCol != lines[i + 1].x && curCol != lines[i + 1].y) {
//             ++i;
//         }
//     }

//     ll ans2 = 0;
//     curCol = lines[1].y;
//     for (int i = 1; i <= m; ++i) {
//         curCol = (curCol == lines[i].x ? lines[i].y : lines[i].x);
//         ans2 += lines[i].v;
//         while (i + 1 <= m && curCol != lines[i + 1].x && curCol != lines[i + 1].y) {
//             ++i;
//         }
//     }

//     cout << max(ans1, ans2) << endl;
// }

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     vector<array<int, 2>> seg(m + 1);
//     vector<ll> val(m + 1);
//     vector<vector<int>> col(n + 1, vector<int>());

//     for (int i = 1; i <= m; ++i) {
//         int x, y;
//         ll v;
//         cin >> x >> y >> v;
//         seg[i][0] = x;
//         seg[i][1] = y;
//         val[i] = v;
//         col[x].push_back(i);
//         col[y].push_back(i);
//     }

//     vector<vector<ll>> f(m + 1, vector<ll>());
//     f[1][0] = f[1][1] = val[1];
//     for (int i = 1; i <= m; ++i) {
//         for (int p = 0; p < 2; ++p) {
//             for (int j : col[seg[i][p]]) {
//                 if (j >= i) break;
//                 if (seg[j][0] == seg[i][p])
//                     f[i][p] = max(f[i][p], f[j][0] + val[i]);
//                 else if (seg[j][1] == seg[i][p])
//                     f[i][p] = max(f[i][p], f[j][1] + val[i]);
//             }
//         }
//     }

//     ll ans = 0;
//     for (int i = 1; i <= m; ++i) {
//         for (int p = 0; p < 2; ++p) {
//             ans = max(ans, f[i][p]);
//         }
//     }

//     cout << ans << endl;
// }

// const int N = 2e5 + 10;
// const ll inf = 1e18;

// struct BIT {
//     int n;
//     vector<ll> tree;

//     BIT(int size) : n(size + 1), tree(size + 1, 0) {
//     }

//     inline int lowbit(int x) {
//         return x & -x;
//     }

//     void update(int i, ll v) {
//         while (i <= n) {
//             tree[i] += v;
//             i += lowbit(i);
//         }
//     }

//     ll query(int i) {
//         ll ans = 0;
//         while (i > 0) {
//             ans += tree[i];
//             i -= lowbit(i);
//         }
//         return ans;
//     }
// };

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     vector<array<int, 2>> seg(m + 1);
//     vector<vector<int>> colPos(n + 1, vector<int>());
//     vector<ll> val(m + 1, 0);
//     vector<array<bool, 2>> isTop(n + 1);
//     BIT bt(n);

//     for (int i = 1; i <= m; ++i) {
//         ll x, y, v;
//         cin >> x >> y >> v;
//         val[i] = v;
//         seg[i][0] = x;
//         seg[i][1] = y;
//         colPos[x].push_back(i);
//         colPos[y].push_back(i);

//         if (bt.query(x)) {
//             isTop[i][0] = false;
//         } else {
//             isTop[i][0] = true;
//         }

//         if (bt.query(y)) {
//             isTop[i][1] = false;
//         } else {
//             isTop[i][1] = true;
//         }

//         int l = min(x, y), r = max(x, y);

//         bt.update(l, +1);
//         bt.update(r + 1, -1);
//     }

//     vector<array<ll, 2>> f(m + 1);

//     for (int i = 1; i <= m; ++i) {
//         for (int p = 0; p < 2; ++p) {
//             f[i][p] = -inf;
//         }
//     }

//     for (int i = 1; i <= m; ++i) {
//         for (int p = 0; p < 2; ++p) {
//             if (isTop[i][p]) {
//                 f[i][p ^ 1] = max(f[i][p ^ 1], val[i]);
//                 f[i][p] = max(-inf, f[i][p]);
//                 continue;
//             }
//             int pVal = seg[i][p];
//             int id =
//                 lower_bound(colPos[pVal].begin(), colPos[pVal].end(), i) - colPos[pVal].begin();
//             if (id == 0) {
//                 f[i][p] = max(-inf, f[i][p]);
//                 f[i][p ^ 1] = max(-inf, f[i][p ^ 1]);
//                 continue;
//             }
//             int j = colPos[pVal][id] - 1;
//             f[i][p] = max(-inf, f[i][p]);
//             f[i][p ^ 1] = max(f[i][p ^ 1], val[i] + (seg[i][p] == seg[j][0] ? f[j][0] :
//             f[j][1]));
//         }
//     }

//     ll ans = 0;
//     for (int i = 1; i <= m; ++i) {
//         for (int p = 0; p < 2; ++p) {
//             ans = max(f[i][p], ans);
//         }
//     }

//     cout << ans << endl;
// }

const ll inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> colPos(n + 1, vector<int>());
    vector<array<int, 2>> seg(m + 1);
    vector<ll> val(m + 1);

    for (int i = 1; i <= m; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        colPos[x].push_back(i);
        colPos[y].push_back(i);
        seg[i][0] = x;
        seg[i][1] = y;
        val[i] = v;
    }

    if (m == 0) {
        cout << 0 << endl;
        return;
    }

    vector<array<ll, 2>> f(m + 1, {-inf, -inf});

    for (int i = 1; i <= m; ++i) {
        for (int p = 0; p < 2; ++p) {
            int pVal = seg[i][p];
            int id =
                lower_bound(colPos[pVal].begin(), colPos[pVal].end(), i) - colPos[pVal].begin();
            if (id == 0) {
                f[i][p] = max(f[i][p], -inf);
                f[i][p ^ 1] = max(f[i][p ^ 1], val[i]);
                continue;
            }
            int j = colPos[pVal][id - 1];
            int lp = (pVal == seg[j][0] ? 0 : 1);

            f[i][p ^ 1] = max(f[i][p ^ 1], f[j][lp] + val[i]);
            f[i][p] = max(f[i][p], -inf);
        }
    }

    ll ans = -inf;
    for (int i = 1; i <= m; ++i) {
        for (int p = 0; p < 2; ++p) {
            ans = max(ans, f[i][p]);
        }
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
