#include "stdlib.h"
#define bool _Bool

struct SegTree {
    int n;
    int *arr;
    int *tree, *setVal;
    bool *hasSet;
};

struct SegTree st;
int *coords;
int coordsSize;

void init(int size) {
    st.n = size;
    st.tree = (int*)calloc((size * 4 + 1), sizeof(int));
    st.setVal = (int*)calloc((size * 4 + 1), sizeof(int));
    st.hasSet = (bool*)calloc((size * 4 + 1), sizeof(bool));
}

void destroy() {
    if (st.tree) free(st.tree);
    if (st.setVal) free(st.setVal);
    if (st.hasSet) free(st.hasSet);
    if (coords) free(coords);
}

int max(int a, int b) {
    return a > b ? a : b;
}

void pushUp(int p) {
    st.tree[p] = max(st.tree[p << 1], st.tree[p << 1 | 1]);
}

void pushDown(int p, int l, int r) {
    if (st.hasSet[p]) {
        st.hasSet[p << 1] = 1;
        st.setVal[p << 1] = st.setVal[p];
        st.tree[p << 1] = st.setVal[p];
        st.hasSet[p << 1 | 1] = 1;
        st.setVal[p << 1 | 1] = st.setVal[p];
        st.tree[p << 1 | 1] = st.setVal[p];
        st.hasSet[p] = 0;
    }
}

void build(int p, int l, int r) {
    if (l == r) {
        st.tree[p] = st.arr[l];
        return;
    }
    int m = l + ((r - l) >> 1);
    build(p << 1, l, m);
    build(p << 1 | 1, m + 1, r);
    pushUp(p);
}

void update(int ql, int qr, int v, int p, int l, int r) {
    if (ql <= l && r <= qr) {
        st.tree[p] = v;
        st.hasSet[p] = 1;
        st.setVal[p] = v;
        return;
    }
    pushDown(p, l, r);
    int m = l + ((r - l) >> 1);
    if (ql <= m) update(ql, qr, v, p << 1, l, m);
    if (qr > m) update(ql, qr, v, p << 1 | 1, m + 1, r);
    pushUp(p);
}

int query(int ql, int qr, int p, int l, int r) {
    if (ql <= l && r <= qr) {
        return st.tree[p];
    }
    pushDown(p, l, r);
    int m = l + ((r - l) >> 1);
    int ans = 0;
    if (ql <= m) ans = max(ans, query(ql, qr, p << 1, l, m));
    if (qr > m) ans = max(ans, query(ql, qr, p << 1 | 1, m + 1, r));
    return ans;
}

void merge(int *a, int l, int m, int r) {
    int *tmp = (int*)malloc(sizeof(int) * (r - l + 1));
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int i = l; i <= r; ++i) {
        a[i] = tmp[i - l];
    }
    free(tmp);
}

void mergeSort(int *a, int l, int r) {
    if (l == r) {
        return;
    }
    int m = l + ((r - l) >> 1);
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

void collect(int** positions, int positionsSize) {
    int *tmp = (int*)malloc(sizeof(int) * positionsSize * 2);
    for (int i = 0; i < positionsSize; ++i) {
        tmp[i << 1] = positions[i][0];
        tmp[i << 1 | 1] = positions[i][0] + positions[i][1] - 1;
    }
    mergeSort(tmp, 0, positionsSize * 2 - 1);
    coords = (int*)malloc(sizeof(int) * positionsSize * 2);
    coordsSize = 0;
    for (int i = 0; i < positionsSize * 2; ++i) {
        if (i == 0 || tmp[i] != tmp[i - 1]) {
            coords[coordsSize++] = tmp[i];
        }
    }
    free(tmp);
}

int rank(int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (coords[m] == x) return m + 1;
        if (coords[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int* fallingSquares(int** positions, int positionsSize, int* positionsColSize, int* returnSize) {
    collect(positions, positionsSize);
    init(coordsSize);
    int *ans = (int*)malloc(sizeof(int) * positionsSize);
    *returnSize = positionsSize;
    int max_h = 0;
    for (int i = 0; i < positionsSize; ++i) {
        int left = positions[i][0];
        int length = positions[i][1];
        int right = left + length - 1;
        int ql = rank(coordsSize, left);
        int qr = rank(coordsSize, right);
        int curr_h = query(ql, qr, 1, 1, coordsSize);
        int new_h = curr_h + length;
        update(ql, qr, new_h, 1, 1, coordsSize);
        max_h = max(max_h, new_h);
        ans[i] = max_h;
    }
    destroy();
    return ans;
}