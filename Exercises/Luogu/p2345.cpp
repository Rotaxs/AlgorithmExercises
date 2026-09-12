#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int MOD = 998244353;

struct BIT {
    int n;
    vector<ll> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, ll k) {
        while (x <= n) {
            tree[x] += k;
            x += lowbit(x);
        }
    }
    ll query(int x) {
        ll res = 0;
        while (x >= 1) {
            res += tree[x];
            x -= lowbit(x);
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pii> a(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
        mx = max(mx, a[i].second);
    }

    sort(a.begin() + 1, a.end());

    BIT sum(mx), cnt(mx);
    ll ans = 0;

    for (int i = 1; i <= n; ++i) {
        int v = a[i].first, x = a[i].second;
        sum.add(x, x);
        cnt.add(x, 1);

        ll sumL = sum.query(x);
        ll cntL = cnt.query(x);
        ll sumR = sum.query(mx) - sumL;
        ll cntR = cnt.query(mx) - cntL;

        ans = (ans + v * (x * cntL - sumL + sumR - x * cntR)) % MOD;
    }

    cout << ans << endl;
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
