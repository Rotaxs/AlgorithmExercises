#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct BIT {
    int n;
    vector<int> arr;
    vector<int> tree;
    BIT(int n) : n(n), arr(n + 1, 0), tree(n + 1, 0) {
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int i, int x) {
        while (i <= n) {
            tree[i] += x;
            i += lowbit(i);
        }
    }
    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i -= lowbit(i);
        }
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> d(n + 1, 0);

    BIT bt(n);

    for (int i = 0; i < n; ++i) {
        d[i + 1] = (s[i] - '0') ^ (s[i + 1] - '0');
        bt.add(i + 1, d[i + 1]);
    }

    auto toggle = [&](int i) {
        int delta = (d[i] == 0 ? +1 : -1);
        d[i] ^= 1;
        bt.add(i, delta);
    };

    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            if (l - 1 >= 1) toggle(l - 1);
            if (r <= n - 1) toggle(r);
        } else if (op == 2) {
            cout << (bt.query(l, r - 1) == r - l ? "Yes" : "No") << endl;
        }
    }
}

// struct segtree {
//     int n;
//     vector<int> arr;
//     vector<int> sum;
//     vector<bool> tag;
//     segtree(int n) : n(n), arr(n + 1, 0), sum((n + 1) << 2, 0), tag((n + 1) << 2, false) {
//     }
//     void pushup(int p) {
//         sum[p] = sum[p << 1] + sum[p << 1 | 1];
//     }
//     void pushdown(int p, int l, int r) {
//         if (tag[p]) {
//             tag[p << 1] = !tag[p << 1];
//             sum[p << 1] = -sum[p << 1];
//             tag[p << 1 | 1] = !tag[p << 1 | 1];
//             sum[p << 1 | 1] = -sum[p << 1 | 1];
//             tag[p] = false;
//         }
//     }
//     void build(int p, int l, int r) {
//         if (l == r) {
//             sum[p] = arr[l];
//             return;
//         }
//         int m = (l + r) >> 1;
//         build(p << 1, l, m);
//         build(p << 1 | 1, m + 1, r);
//         pushup(p);
//     }
//     int query(int ql, int qr, int p, int l, int r) {
//         if (ql <= l && r <= qr) {
//             return sum[p];
//         }
//         pushdown(p, l, r);
//         int m = (l + r) >> 1;
//         int res = 0;
//         if (ql <= m) res += query(ql, qr, p << 1, l, m);
//         if (qr > m) res += query(ql, qr, p << 1 | 1, m + 1, r);
//         return res;
//     }
//     void flip(int ql, int qr, int p, int l, int r) {
//         if (ql <= l && r <= qr) {
//             tag[p] = !tag[p];
//             sum[p] = -sum[p];
//             return;
//         }
//         pushdown(p, l, r);
//         int m = (l + r) >> 1;
//         if (ql <= m) flip(ql, qr, p << 1, l, m);
//         if (qr > m) flip(ql, qr, p << 1 | 1, m + 1, r);
//         pushup(p);
//     }
//     int query(int l, int r) {
//         return query(l, r, 1, 1, n);
//     }
//     void flip(int l, int r) {
//         flip(l, r, 1, 1, n);
//     }
// };

// void solve() {
//     int n, q;
//     cin >> n >> q;
//     string s;
//     cin >> s;

//     segtree seg(n);

//     for (int i = 0; i < n; ++i) {
//         int c = s[i] - '0';
//         if ((c == 1 && i % 2 == 1) || (c == 0 && i % 2 == 0)) {
//             ++seg.arr[i + 1];
//         } else {
//             --seg.arr[i + 1];
//         }
//     }
//     seg.build(1, 1, n);

//     while (q--) {
//         int op, l, r;
//         cin >> op >> l >> r;
//         if (op == 1) {
//             seg.flip(l, r);
//         } else if (op == 2) {
//             cout << (abs(seg.query(l, r)) == r - l + 1 ? "Yes" : "No") << endl;
//         }
//     }
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}
