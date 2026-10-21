#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n * m, 0);

    for (int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        a[x * m + y] = i;
    }

    int u1, v1, u2, v2;
    cin >> u1 >> v1 >> u2 >> v2;
    --u1;
    --v1;
    --u2;
    --v2;
    int S = (u2 - u1 + 1) * (v2 - v1 + 1);

    vector<int> q(n * m), vis(n * m, 0);
    int stamp = 0;
    const int mv[] = {-1, 0, 1, 0, -1};

    auto check = [&](int x) -> bool {
        for (int r = u1; r <= u2; ++r) {
            for (int c = v1; c <= v2; ++c) {
                if (a[r * m + c] > x) return false;
            }
        }

        int head = 0, tail = 0;
        int E = 0;

        int start = u1 * m + v1;
        q[tail++] = start;
        vis[start] = ++stamp;

        while (head < tail) {
            int f = q[head++];
            if (a[f] == 0 && ++E >= S) return true;

            int r = f / m, c = f % m;

            for (int d = 0; d < 4; ++d) {
                int nr = r + mv[d], nc = c + mv[d + 1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int nxt = nr * m + nc;
                if (vis[nxt] == stamp || a[nxt] > x) continue;
                vis[nxt] = stamp;
                q[tail++] = nxt;
            }
        }

        return false;
    };

    int l = -1, r = k + 1;
    while (l + 1 != r) {
        int mid = l + (r - l) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }

    cout << (r == k + 1 ? -1 : r) << endl;
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
