#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 10;

struct {
    int to, ne, w;
} edge[N << 1];
int head[N], cnt;

int n, k;

void addEdge(int u, int v, int w) {
    edge[++cnt] = {v, head[u], w};
    head[u] = cnt;
}

bool check(ll d) {

    for (int u = 1; u <= n; ++u) {
        for (int e = head[u]; e; e = edge[e].ne) {
            int w = edge[e].w;
            if (w > d) return false;
        }
    }

    vector<ll> h(n + 1, 0);

    function<int(int, int)> dfs = [&](int u, int fa) {
        int cnt = 0;
        ll mx1 = 0, mx2 = 0;
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            int w = edge[e].w;

            if (v == fa) continue;

            cnt += dfs(v, u);

            ll a = h[v] + w;

            if (a > d) {
                ++cnt;
                a = w;
            }

            if (a >= mx1) {
                mx2 = mx1;
                mx1 = a;
            } else if (a > mx2) {
                mx2 = a;
            }
        }
        if (mx1 + mx2 > d) {
            ++cnt;
            h[u] = 0;
        } else {
            h[u] = mx1;
        }
        return cnt;
    };

    int c = dfs(1, 0);

    return (c > k ? false : true);
}

void solve() {
    cin >> n >> k;

    int mx = 0;
    ll sum = 0;

    for (int i = 1; i <= n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        mx = max(mx, w);
        sum += w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    ll l = mx - 1, r = sum + 1;
    while (l + 1 != r) {
        ll mid = l + (r - l) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }

    cout << r << endl;
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
