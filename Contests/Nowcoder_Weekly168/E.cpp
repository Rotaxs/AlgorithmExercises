#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct Stuff {
    ll val;
    int flag;
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<Stuff> A(n + 1), B(m + 1);
    vector<ll> preA(n + 1, 0), preB(m + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> A[i].val >> A[i].flag;
        preA[i] = preA[i - 1] + A[i].val;
    }
    for (int j = 1; j <= m; ++j) {
        cin >> B[j].val >> B[j].flag;
        preB[j] = preB[j - 1] + B[j].val;
    }

    vector<vector<pair<bool, bool>>> f(n + 1, vector<pair<bool, bool>>(m + 1, {false, false}));
    f[0][0] = {true, true};

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i + j > k) continue;

            if (i < n && f[i][j].first) {
                f[i + 1][j].second = true;
                if (A[i + 1].flag == 0) {
                    f[i + 1][j].first = true;
                }
            }

            if (j < m && f[i][j].second) {
                f[i][j + 1].first = true;
                if (B[j + 1].flag == 0) {
                    f[i][j + 1].second = true;
                }
            }
        }
    }

    ll ans = -1e18;
    for (int i = 0; i <= min(n, k); ++i) {
        int j = k - i;
        if (j > m) continue;

        if (f[i][j].first || f[i][j].second) {
            ans = max(ans, preA[i] + preB[j]);
        }
    }

    if (ans == -1e18) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans << endl;
    }
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
