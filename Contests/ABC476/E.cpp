#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct SegTree {
    int n;
    vector<int> arr, mx, mi, setVal;
    vector<bool> hasSet;

    SegTree(int n)
        : n(n), arr(n + 1), mi((n + 1) << 2, 1e9), mx((n + 1) << 2, 0), setVal((n + 1) << 2, 0),
          hasSet((n + 1) << 2, 0) {
    }
    void pushUp(int p) {
        mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
        mi[p] = min(mi[p << 1], mi[p << 1 | 1]);
    }
    void build(int p, int l, int r) {
        if (l == r) {
            mx[p] = arr[l];
            mi[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m);
        build(p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    void modify(int i, int v, int p, int l, int r) {
        if (l == i && i == r) {
            mi[p] = v;
            mx[p] = v;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) modify(i, v, p << 1, l, m);
        if (i > m) modify(i, v, p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    int queryMax(int ql, int qr, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            return mx[p];
        }
        int m = (l + r) >> 1;
        int res = 0;
        if (ql <= m) res = max(res, queryMax(ql, qr, p << 1, l, m));
        if (qr > m) res = max(res, queryMax(ql, qr, p << 1 | 1, m + 1, r));
        return res;
    }
    int queryMin(int ql, int qr, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            return mi[p];
        }
        int m = (l + r) >> 1;
        int res = 1e9;
        if (ql <= m) res = min(res, queryMin(ql, qr, p << 1, l, m));
        if (qr > m) res = min(res, queryMin(ql, qr, p << 1 | 1, m + 1, r));
        return res;
    }
    void modify(int i, int v) {
        modify(i, v, 1, 1, n);
    }
    int queryMax(int l, int r) {
        return queryMax(l, r, 1, 1, n);
    }
    int queryMin(int l, int r) {
        return queryMin(l, r, 1, 1, n);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> pos(n + 1);

    SegTree seg(n);

    for (int i = 1; i <= n; ++i) {
        cin >> seg.arr[i];
        pos[seg.arr[i]] = i;
    }

    seg.build(1, 1, n);

    while (m--) {
        int l, r;
        cin >> l >> r;
        int mi = seg.queryMin(l, r);
        int mx = seg.queryMax(l, r);
        int miPos = pos[mi];
        int mxPos = pos[mx];
        seg.modify(miPos, mx);
        seg.modify(mxPos, mi);
        seg.arr[miPos] = mx;
        seg.arr[mxPos] = mi;
        pos[mi] = mxPos;
        pos[mx] = miPos;
    }

    for (int i = 1; i <= n; ++i) {
        cout << seg.arr[i] << ' ';
    }
    cout << endl;
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
