#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct BIT {
    int n;
    vector<ll> tree;
    BIT(int n) : n(n), tree(n + 1) {
    }
    int lowbit(int x) {
        return x & -x;
    }
    void update(int i, int x) {
        while (i <= n) {
            tree[i] += x;
            i += lowbit(i);
        }
    }
    ll query(int i) {
        ll res = 0;
        while (i > 0) {
            res += tree[i];
            i -= lowbit(i);
        }
        return res;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;

    BIT bt(n);

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        bt.update(i, a);
    }

    ll res = 0;
    for (int i = n; i >= 1; --i) {
        int limit = min(n, i + k);
        ll x = bt.query(limit) - bt.query(i);
        bt.update(i, x);
    }

    res = bt.query(n) % 2;

    cout << (res == 0 ? "Bob" : "Alice") << endl;
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
