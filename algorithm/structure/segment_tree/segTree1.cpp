#include "bits/stdc++.h"
using namespace std;

using ll = long long;

const int N = 1e5 + 10;
int arr[N];
ll tree[N << 2], add[N << 2];
int n;

void pushUp(int p) {
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}

void pushDown(int p, int l, int r) {
    if (add[p]) {
        int m = (l + r) >> 1;
        add[p << 1] += add[p];
        add[p << 1 | 1] += add[p];
        tree[p << 1] += (m - l + 1) * add[p];
        tree[p << 1 | 1] += (r - m) * add[p];
        add[p] = 0;
    }
}

void build(int l = 1, int r = n, int p = 1) {
    add[p] = 0;
    if (l == r) {
        tree[p] = arr[l];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, p << 1);
    build(m + 1, r, p << 1 | 1);
    pushUp(p);
}

ll query(int ql, int qr, int l = 1, int r = n, int p = 1) {
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

void rangeAdd(int ql, int qr, ll v, int l = 1, int r = n, int p = 1) {
    if (ql <= l && r <= qr) {
        add[p] += v;
        tree[p] += (r - l + 1) * v;
        return;
    }
    pushDown(p, l, r);
    int m = (l + r) >> 1;
    if (ql <= m) rangeAdd(ql, qr, v, l, m, p << 1);
    if (qr > m) rangeAdd(ql, qr, v, m + 1, r, p << 1 | 1);
    pushUp(p);
}