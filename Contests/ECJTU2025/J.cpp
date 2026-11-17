#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

static int dr[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};

void solve() {
    int n; cin >> n;
    cin.ignore();
    vector<string> mat(n + 1, string(n + 1, ' '));
    for (int i = 1; i <= n; ++i) {
        string line;
        getline(cin, line);
        for (int j = 1; j <= n; ++j) {
            mat[i][j] = line[j - 1];
        }
    }

    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));

    vector<pair<int, int>> path;
    bool ok = false;
    function<void(int, int)> dfs = [&](int r, int c) {
        if (r == n - 1 && c == n - 1) {
            for (auto [x, y] : path) {
                if (x == n - 1 && y == n - 1) continue;
                mat[x][y] = '*';
            }
            ok = true;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr <= 0 || nc <= 0 || nr > n || nc > n) continue;
            if (mat[nr][nc] == '#' || vis[nr][nc]) continue;
            vis[nr][nc] = true;
            path.push_back({nr, nc});
            dfs(nr, nc);
            if (ok) return;
            path.pop_back();
        }
    };

    // path.push_back({2, 2});
    dfs(2, 2);

    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= n; ++c) {
            cout << mat[r][c];
        }
        cout << endl;
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
