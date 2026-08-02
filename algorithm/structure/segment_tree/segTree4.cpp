#include "bits/stdc++.h"
using namespace std;

using ll = long long;

struct SegTree {
private:
    int n;
    vector<int> arr;
    vector<ll> tree, setVal;
    vector<bool> hasSet;

    void pushDown(int p, int l, int r) {
        if (hasSet[p]) {
            int m = (l + r) >> 1;
            hasSet[p << 1] = true;
            setVal[p << 1] = setVal[p];
            tree[p << 1] = (m - l + 1) * setVal[p];
            hasSet[p << 1 | 1] = true;
            setVal[p << 1 | 1] = setVal[p];
            tree[p << 1 | 1] = (r - m) * setVal[p];
            hasSet[p] = false;
            setVal[p] = 0;
        }
    }

    void pushUp(int p) {
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }

    ll query(int ql, int qr, int l, int r, int p) {
        if (ql <= l && r <= qr) {
            return tree[p];
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        ll ans = 0;
        if (ql <= m) ans += query(ql, qr, l, m, p << 1);
        if (qr > m) ans += query(ql, qr, m + 1, r, p << 1 | 1);
        return ans;
    }

    void rangeSet(int ql, int qr, ll v, int l, int r, int p) {
        if (ql <= l && r <= qr) {
            hasSet[p] = true;
            setVal[p] = v;
            tree[p] = (r - l + 1) * v;
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) rangeSet(ql, qr, v, l, m, p << 1);
        if (qr > m) rangeSet(ql, qr, v, m + 1, r, p << 1 | 1);
        pushUp(p);
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
        arr.resize(n + 1);
        tree.resize((n + 1) << 2, 0);
        setVal.resize((n + 1) << 2, 0);
        hasSet.resize((n + 1) << 2, false);
    }

    void read() {
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        build(1, n, 1);
    }

    void modify(int l, int r, ll v) {
        rangeSet(l, r, v, 1, n, 1);
    }

    void modify(int i, ll v) {
        modify(i, i, v);
    }

    ll query(int l, int r) {
        return query(l, r, 1, n, 1);
    }

    ll query(int i) {
        return query(i, i);
    }
};

int main()
{
    return 0;
}