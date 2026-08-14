#include "bits/stdc++.h"
using namespace std;

using ll = long long;

const int N = 1e5 + 10;

int arr[N];
ll tree[N << 2], addVal[N << 2], setVal[N << 2];
bool hasSet[N << 2];
int n;

void pushUp(int p) {
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}

void pushDown(int p, int l, int r) {
    int m = (l + r) >> 1;
    if (hasSet[p]) {
        hasSet[p << 1] = true;
        setVal[p << 1] = setVal[p];
        addVal[p << 1] = 0;
        tree[p << 1] = (m - l + 1) * setVal[p];

        hasSet[p << 1 | 1] = true;
        setVal[p << 1 | 1] = setVal[p];
        addVal[p << 1 | 1] = 0;
        tree[p << 1 | 1] = (r - m) * setVal[p];

        hasSet[p] = false;
    }

    if (addVal[p]) {
        addVal[p << 1] += addVal[p];
        tree[p << 1] += (m - l + 1) * addVal[p];
        addVal[p << 1 | 1] += addVal[p];
        tree[p << 1 | 1] += (r - m) * addVal[p];
        addVal[p] = 0;
    }
}

void build(int l = 1, int r = n, int p = 1) {
    hasSet[p] = false;
    addVal[p] = 0;
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
        addVal[p] += v;
        tree[p] += (r - l + 1) * v;
        return;
    }
    pushDown(p, l, r);
    int m = (l + r) >> 1;
    if (ql <= m) rangeAdd(ql, qr, v, l, m, p << 1);
    if (qr > m) rangeAdd(ql, qr, v, m + 1, r, p << 1 | 1);
    pushUp(p);
}

void rangeSet(int ql, int qr, ll v, int l = 1, int r = n, int p = 1) {
    if (ql <= l && r <= qr) {
        hasSet[p] = true;
        setVal[p] = v;
        addVal[p] = 0;
        tree[p] = (r - l + 1) * v;
        return;
    }
    pushDown(p, l, r);
    int m = (l + r) >> 1;
    if (ql <= m) rangeSet(ql, qr, v, l, m, p << 1);
    if (qr > m) rangeSet(ql, qr, v, m + 1, r, p << 1 | 1);
    pushUp(p);
}

int main()
{

    return 0;
}