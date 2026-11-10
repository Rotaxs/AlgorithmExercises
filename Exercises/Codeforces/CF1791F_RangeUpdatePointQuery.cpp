#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct SegTree {
    int n;
    vector<int> addVal, sum;
    SegTree(int n) : n(n), sum((n + 1) << 2, 0), addVal((n + 1) << 2, 0) {
    }
    void pushUp(int p) {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
    }
    void pushDown(int p, int l, int r) {
        if (addVal[p]) {
            int m = (l + r) >> 1;
            addVal[p << 1] += addVal[p];
            sum[p << 1] += (m - l + 1) * addVal[p];
            addVal[p << 1 | 1] += addVal[p];
            sum[p << 1 | 1] += (r - m) * addVal[p];
            addVal[p] = 0;
        }
    }
    void add(int ql, int qr, int v, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            sum[p] += (r - l + 1) * v;
            addVal[p] += v;
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) add(ql, qr, v, p << 1, l, m);
        if (qr > m) add(ql, qr, v, p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    int query(int i, int p, int l, int r) {
        if (l == r) {
            return sum[p];
        }
        pushDown(p, l, r);
        int res = 0;
        int m = (l + r) >> 1;
        if (i <= m)
            res = query(i, p << 1, l, m);
        else
            res = query(i, p << 1 | 1, m + 1, r);
        return res;
    }
    void add(int l, int r, int v) {
        add(l, r, v, 1, 1, n);
    }
    int query(int i) {
        return query(i, 1, 1, n);
    }
};

struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 1) {
    }
    static int lowbit(int x) {
        return x & -x;
    }
    void add(int i, int v) {
        while (i <= n) {
            tree[i] += v;
            i += lowbit(i);
        }
    }
    int query(int i) {
        int res = 0;
        while (i >= 1) {
            res += tree[i];
            i -= lowbit(i);
        }
        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[i].push_back(x);
        while (x >= 10) {
            int tmp = x;
            x = 0;
            while (tmp) {
                x += tmp % 10;
                tmp /= 10;
            }
            a[i].push_back(x);
        }
    }

    // SegTree seg(n);
    // while (q--) {
    //     int op;
    //     cin >> op;
    //     if (op == 1) {
    //         int l, r;
    //         cin >> l >> r;
    //         seg.add(l, r, 1);
    //     } else if (op == 2) {
    //         int x;
    //         cin >> x;
    //         int c = seg.query(x);
    //         if (c >= a[x].size()) {
    //             cout << a[x].back() << endl;
    //         } else {
    //             cout << a[x][c] << endl;
    //         }
    //     }
    // }

    BIT bt(n);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            bt.add(l, 1);
            bt.add(r + 1, -1);
        } else if (op == 2) {
            int x;
            cin >> x;
            int c = bt.query(x);
            if (c >= a[x].size()) {
                cout << a[x].back() << endl;
            } else {
                cout << a[x][c] << endl;
            }
        }
    }
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
