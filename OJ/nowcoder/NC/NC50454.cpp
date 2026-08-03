#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

struct SegTree {
    int n;
    vector<int> arr;
    vector<ll> tree, addVal;
    SegTree(int size) {
        n = size;
        arr.resize(n + 1);
        tree.resize((n + 1) << 2, 0);
        addVal.resize((n + 1) << 2, 0);
    }
    void read() {
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        build(1, 1, n);
    }
    void pushUp(int p) {
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }
    void pushDown(int p, int l, int r) {
        if (addVal[p]) {
            int m = (l + r) >> 1;
            addVal[p << 1] += addVal[p];
            tree[p << 1] += (m - l + 1) * addVal[p];
            addVal[p << 1 | 1] += addVal[p];
            tree[p << 1 | 1] += (r - m) * addVal[p];
            addVal[p] = 0;
        }
    }
    void build(int p, int l, int r) {
        if (l == r) {
            tree[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m);
        build(p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    ll query(int ql, int qr, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            return tree[p];
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        ll ans = 0;
        if (ql <= m) ans += query(ql, qr, p << 1, l, m);
        if (qr > m) ans += query(ql, qr, p << 1 | 1, m + 1, r);
        return ans;
    }
    void rangeAdd(int ql, int qr, ll v, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            addVal[p] += v;
            tree[p] += (r - l + 1) * v;
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) rangeAdd(ql, qr, v, p << 1, l, m);
        if (qr > m) rangeAdd(ql, qr, v, p << 1 | 1, m + 1, r);
        pushUp(p);
    }
};

void solve()
{
    int n, q; cin >> n >> q;
    SegTree st(n);
    st.read();
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; ll x; cin >> l >> r >> x;
            st.rangeAdd(l, r, x, 1, 1, n);
        } else if (op == 2) {
            int l, r; cin >> l >> r;
            cout << st.query(l, r, 1, 1, n) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    // cin >> _;
    while (_--) solve();
    
    return 0;
}