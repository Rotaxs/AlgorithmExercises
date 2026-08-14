#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int mv[5] = {-1, 0, 1, 0, -1};

struct Node 
{ 
    int x, y, h; 
    bool operator<(const Node &other) const
    {
        return h > other.h;
    }
};

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> h(n + 1, vector<int>(m + 1));
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
    vector<Node> all;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> h[i][j];
            all.push_back({j, i, h[i][j]});
        }
    }
    sort(all.begin(), all.end());
    for (auto &[cx, cy, ch] : all) {
        bool zero = false;
        for (int i = 0; i < 4; i++) {
            int nx = cx + mv[i], ny = cy + mv[i + 1];
            if (nx <= 0 || ny <= 0 || nx > m || ny > n) continue;
            if (h[ny][nx] < h[cy][cx]) continue;
            if (!f[ny][nx]) zero = true;
        }
        if (zero) f[cy][cx] = true;
    }
    int q; cin >> q;
    while (q--) {
        int r, c; cin >> r >> c;
        cout << (f[r][c] ? "First\n" : "Second\n");
    }
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