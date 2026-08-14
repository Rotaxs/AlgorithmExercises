#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct SegTree {
private:
    int n;
    vector<int> arr;
    vector<ll> tree, addVal;

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

    void rangeAdd(int ql, int qr, ll v, int l, int r, int p) {
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

public:
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

void solve()
{
    int n, m; cin >> n >> m;
    SegTree st(n);
    st.read();
    while (m--) {
        int f, x, y; cin >> f >> x >> y;
        if (f == 1) {
            st.add(x, y);
        } else if (f == 2) {
            cout << st.query(x, y) << endl;
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