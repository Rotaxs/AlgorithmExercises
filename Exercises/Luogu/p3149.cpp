#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct BIT {
    int n;
    vector<ll> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int i, ll x) {
        while (i <= n) {
            tree[i] += x;
            i += lowbit(i);
        }
    }
    ll query(int i) {
        ll res = 0;
        while (i >= 1) {
            res += tree[i];
            i -= lowbit(i);
        }
        return res;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    BIT bt(b.size());
    vector<int> smaller(n, 0);
    for (int i = 0; i < n; ++i) {
        int rk = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        bt.add(rk, 1);
        smaller[i] = bt.query(rk);
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
