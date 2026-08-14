#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int dr[2] = {1, 0}, dc[2] = {0, 1};

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    if (n == 1 || m == 1) {
        int p = a[1][1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i][j] != p) {
                    cout << "-1\n";
                    return;
                }
            }
        }
        cout << "0\n";
        return;
    }
    if (a[1][1] != a[n][m]) {
        cout << -1 << endl;
        return;
    }

    ll x = a[1][2] + a[2][1] - a[1][1];
    vector<vector<ll>> R(n + 1, vector<ll>(m + 1 , 0)), D(n, vector<ll>(m + 1, 0));
    for (int j = m; j >= 1; --j) {
        R[n][j] = x - a[n][j];
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            if (j == 1) D[i][j] = x - a[i + 1][j];
            else D[i][j] = x - a[i + 1][j] - R[i + 1][j - 1];
            R[i][j] = x - a[i][j] - D[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) continue;
            if (a[i][j] != x) {
                cout << "-1\n";
                return;
            }
        }
    }

    cout << x - a[1][1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}