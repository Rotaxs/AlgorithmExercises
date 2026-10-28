// ========== 2026/10/28 ===============
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> isFriend(k + 1, false);

    for (int i = 1; i <= n; ++i) {
        int f;
        cin >> f;
        isFriend[f] = true;
    }

    int ans1 = 0;

    vector<int> d(k + 1, 0);
    vector<pair<int, int>> edge;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        if (isFriend[u] && isFriend[v]) {
            ++ans1;
        } else if (u == v) {
            ++d[u];
        } else if (isFriend[u]) {
            ++d[v];
        } else if (isFriend[v]) {
            ++d[u];
        } else {
            if (u > v) swap(u, v);
            edge.push_back({u, v});
        }
    }

    int mx1 = 0, mx2 = 0;
    for (int u = 1; u <= k; ++u) {
        if (d[u] >= mx1) {
            mx2 = mx1;
            mx1 = d[u];
        } else if (d[u] > mx2) {
            mx2 = d[u];
        }
    }

    sort(edge.begin(), edge.end());

    int len = edge.size();
    int ans2 = 0;
    for (int i = 0, j; i < len; i = j + 1) {
        j = i;
        while (j + 1 < len && edge[j] == edge[j + 1]) {
            ++j;
        }
        int w = j - i + 1;
        int u = edge[i].first, v = edge[i].second;
        ans2 = max(ans2, d[u] + d[v] + w);
    }
    ans2 = max(ans2, mx1 + mx2);

    cout << ans1 + ans2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;

// void solve() {
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<bool> isFriend(k + 1, false);
//     for (int i = 1; i <= n; ++i) {
//         int f;
//         cin >> f;
//         isFriend[f] = true;
//     }

//     int ans1 = 0;

//     vector<int> d(k + 1, 0);
//     vector<pair<int, int>> edge;

//     for (int i = 1; i <= m; ++i) {
//         int a, b;
//         cin >> a >> b;
//         if (isFriend[a] && isFriend[b]) {
//             ++ans1;
//         } else if (a == b) {
//             ++d[a];
//         } else if (isFriend[a]) {
//             ++d[b];
//         } else if (isFriend[b]) {
//             ++d[a];
//         } else {
//             if (a > b) swap(a, b);
//             edge.push_back({a, b});
//         }
//     }

//     int mx1 = 0, mx2 = 0;
//     for (int u = 1; u <= k; ++u) {
//         if (d[u] >= mx1) {
//             mx2 = mx1;
//             mx1 = d[u];
//         } else if (d[u] > mx2) {
//             mx2 = d[u];
//         }
//     }

//     sort(edge.begin(), edge.end());
//     int len = edge.size();
//     int ans2 = 0;
//     for (int i = 0, j; i < len; i = j + 1) {
//         int u = edge[i].first, v = edge[i].second;
//         j = i;
//         while (j + 1 < len && edge[j + 1] == edge[j]) {
//             ++j;
//         }
//         int w = j - i + 1;
//         ans2 = max(ans2, d[u] + d[v] + w);
//     }
//     ans2 = max(ans2, mx1 + mx2);

//     int ans = ans1 + ans2;
//     cout << ans << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int _ = 1;
//     cin >> _;
//     while (_--)
//         solve();

//     return 0;
// }
