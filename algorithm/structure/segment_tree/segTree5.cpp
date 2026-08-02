#include "bits/stdc++.h"
using namespace std;

using ll = long long;

struct SegTree {
private:
    int n;
    vector<int> arr;
    vector<ll> tree, addVal;

    void pushUp(int p) {
        tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
    }

    void pushDown(int p, int l, int r) {
        if (addVal[p]) {
            addVal[p << 1] += addVal[p];
            tree[p << 1] += addVal[p];
            addVal[p << 1 | 1] += addVal[p];
            tree[p << 1 | 1] += addVal[p];
            addVal[p] = 0;
        }
    }

    void rangeAdd(int ql, int qr, ll v, int l, int r, int p) {
        if (ql <= l && r <= qr) {
            addVal[p] += v;
            tree[p] += v;
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) rangeAdd(ql, qr, v, l, m, p << 1);
        if (qr > m) rangeAdd(ql, qr, v, m + 1, r, p << 1 | 1);
        pushUp(p);
    }

    ll query(int ql, int qr, int l, int r, int p) {
        if (ql <= l && r <= qr) {
            return tree[p];
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        ll ans = -4e18;
        if (ql <= m) ans = max(ans, query(ql, qr, l, m, p << 1));
        if (qr > m) ans = max(ans, query(ql, qr, m + 1, r, p << 1 | 1));
        return ans;
    }

    void build(int l, int r, int p) {
        if (l == r) {
            tree[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, p << 1);
        build(m + 1, r, p << 1 | 1);
        pushUp(p);
    }

public:
    SegTree(int size) {
        n = size;
        arr.resize(n + 1, 0);
        tree.resize((n + 1) << 2, 0);
        addVal.resize((n + 1) << 2, 0);
    }

    void read() {
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        build(1, n, 1);
    }

    void add(int l, int r, ll v) {
        rangeAdd(l, r, v, 1, n, 1);
    }

    void add(int i, ll v) {
        add(i, i, v);
    }

    ll query(int l, int r) {
        return query(l, r, 1, n, 1);
    }

    ll query(int i) {
        return query(i, i);
    }
};