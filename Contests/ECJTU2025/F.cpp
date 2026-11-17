#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e7 + 10;

int p[N], cnt;
bool vis[N];

void euler(int n) {
    vis[0] = vis[1] = true;
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) p[++cnt] = i;
        for (int j = 1; j <= cnt && i * p[j] <= n; ++j) {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
}

void solve() {
    int n, x; cin >> n >> x;
    if (!(p[x] > n && p[x] < 2 * n)) {
        cout << "Smooth" << endl;
        return;
    }

    int id = lower_bound(p + 1, p + 1 + x, n) - p;
    cout << "Rough " << (p[id] == n ? x - id : x - id + 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    euler(N - 1);

    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}
