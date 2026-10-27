#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct BIT {
    int n;
    vector<int> arr;
    vector<ll> tree;
    BIT(int n) : n(n), arr(n + 1, 0), tree(n + 1, 0) {
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
    ll query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void solve() {
    int n;
    cin >> n;
    BIT bt(n);

    bool same = false;
    ll cnt = 0;

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (!same && bt.query(a, a) >= 1) {
            same = true;
        }
        bt.add(a, 1);
        cnt += i - bt.query(a);
    }

    if (same) {
        cout << "YES" << endl;
        return;
    }

    cout << (cnt % 2 == 0 ? "YES" : "NO") << endl;
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
