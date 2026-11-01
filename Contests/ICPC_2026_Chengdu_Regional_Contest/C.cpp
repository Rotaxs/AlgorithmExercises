#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 101;
const int MOD = 998244353;

int f[N][N][N * N];

void init() {
    int limit = 5050;
    f[1][0][0] = 1;
    for (int i = 1; i < N - 1; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            for (int k = 0; k <= limit; ++k) {
                if (k + j <= limit) f[i + 1][j][k + j] = (f[i + 1][j][k + j] + f[i][j][k]) % MOD;
                if (k + j + 1 <= limit)
                    f[i + 1][j + 1][k + j + 1] = (f[i + 1][j + 1][k + j + 1] + f[i][j][k]) % MOD;
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> dp(n + 1, 0), ndp(n + 1);
    int lastS = 0, lastP = 1;
    dp[0] = 1;

    while (m--) {
        int p, s;
        cin >> p >> s;

        fill(ndp.begin(), ndp.end(), 0);

        for (int a = 0; a < lastP; ++a) {
            if (dp[a] == 0) continue;
            int l = p - lastP;
            int sum = s - lastS - l * a;
            if (sum < 0 || sum > l * (l + 1) / 2) continue;

            for (int j = a; j <= a + l; ++j) {
                ndp[j] = (ndp[j] + dp[a] * f[l + 1][j - a][s - lastS - l * a]) % MOD;
            }
        }
        dp.swap(ndp);
        lastP = p;
        lastS = s;
    }

    ll ans = 0;
    for (int a = 0; a <= lastP; ++a) {
        ans = (ans + dp[a]) % MOD;
    }
    for (int a = lastP + 1; a <= n; ++a) {
        ans = ans * 2 % MOD;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}

// void dfs(int i, ll a, ll s) {
//     if (i == n) {
//         if (!vis[i] || (vis[i] && s == S[i])) ++cnt;
//         return;
//     }
//     if (vis[i] && s != S[i]) return;
//     dfs(i + 1, a + 1, s + a + 1);
//     dfs(i + 1, a, s + a);
// }

// void setv(int i, ll v) {
//     S[i] = v;
//     vis[i] = true;
// }
