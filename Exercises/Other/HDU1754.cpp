#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

struct SegTree {
    int n;
    vector<int> arr;
    vector<int> tree, setVal;
    vector<bool> hasSet;
    SegTree(int size) {
        n = size;
        arr.resize(n + 1);
        tree.resize((n + 1) << 2);
        setVal.resize((n + 1) << 2);
        hasSet.resize((n + 1) << 2);
    }
    void read() {
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        build(1, 1, n);
    }
    void pushUp(int p) {
        tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
    }
    void pushDown(int p, int l, int r) {
        if (hasSet[p]) {
            hasSet[p << 1] = true;
            setVal[p << 1] = setVal[p];
            tree[p << 1] = setVal[p];
            hasSet[p << 1 | 1] = true;
            setVal[p << 1 | 1] = setVal[p];
            tree[p << 1 | 1] = setVal[p];
            hasSet[p] = false;
        }
    }
    void build(int p, int l, int r) {
        if (l == r) {
            tree[p] = arr[l];
            return;
        }
        int m = l + ((r - l) >> 1);
        build(p << 1, l, m);
        build(p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    void rangeSet(int ql, int qr, int v, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            tree[p] = v;
            setVal[p] = v;
            hasSet[p] = true;
            return;
        }
        pushDown(p, l, r);
        int m = l + ((r - l) >> 1);
        if (ql <= m) rangeSet(ql, qr, v, p << 1, l, m);
        if (qr > m) rangeSet(ql, qr, v, p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    void update(int i, int v) {
        rangeSet(i, i, v, 1, 1, n);
    }
    int query(int ql, int qr, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            return tree[p];
        }
        pushDown(p, l, r);
        int m = l + ((r - l) >> 1);
        int ans = -inf;
        if (ql <= m) ans = max(ans, query(ql, qr, p << 1, l, m));
        if (qr > m) ans = max(ans, query(ql, qr, p << 1 | 1, m + 1, r));
        return ans;
    }
    int query(int l, int r) {
        if (l > r) swap(l, r);
        return query(l, r, 1, 1, n);
    }
};

void solve(int n, int m)
{
    SegTree st(n); st.read();
    while (m--) {
        char op; cin >> op;
        int a, b; cin >> a >> b;
        if (op == 'Q') {
            cout << st.query(a, b) << endl;
        } else if (op == 'U') {
            st.update(a, b);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    while (cin >> n >> m) {
        solve(n, m);
    }
    
    return 0;
}