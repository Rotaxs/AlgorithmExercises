#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

// const int inf = 0x3f3f3f3f;
// const ll inf  = 2e18;

struct SegTree {
    int n;
    vector<int> arr;
    vector<int> tree, setVal;
    vector<bool> hasSet;

    SegTree(int size) {
        n = size;
        arr.resize(n + 1, 0);
        tree.resize((n + 1) << 2, 0);
        setVal.resize((n + 1) << 2, 0);
        hasSet.resize((n + 1) << 2, false);
        build(1, 1, n);
    }
    
    void pushUp(int p) {
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }

    void pushDown(int p, int l, int r) {
        if (hasSet[p]) {
            int m = (l + r) >> 1;
            hasSet[p << 1] = true;
            setVal[p << 1] = setVal[p];
            tree[p << 1] = (m - l + 1) * setVal[p];
            hasSet[p << 1 | 1] = true;
            setVal[p << 1 | 1] = setVal[p];
            tree[p << 1 | 1] = (r - m) * setVal[p];
            hasSet[p] = 0;
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

    void rangeSet(int ql, int qr, int v, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            tree[p] = (r - l + 1) * v;
            hasSet[p] = true;
            setVal[p] = v;
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) rangeSet(ql, qr, v, p << 1, l, m);
        if (qr > m) rangeSet(ql, qr, v, p << 1 | 1, m + 1, r);
        pushUp(p);
    }

    int query(int ql, int qr, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            return tree[p];
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        int ans = 0;
        if (ql <= m) ans += query(ql, qr, p << 1, l, m);
        if (qr > m) ans += query(ql, qr, p << 1 | 1, m + 1, r);
        return ans;
    }

    int query(int l, int r) {
        return query(l, r, 1, 1, n);
    }

    void clear(int l, int r) {
        rangeSet(l, r, 0, 1, 1, n);
    }

    void update(int l, int r) {
        rangeSet(l, r, 1, 1, 1, n);
    }

    int getZeroCnt(int l, int r) {
        int all = r - l + 1;
        int one = query(l, r);
        return all - one;
    }

    int findZero(int from, int k) {
        int l = from - 1, r = n + 1;
        while ((l + 1) != r) {
            int m = (l + r) >> 1;
            if (getZeroCnt(from, m) >= k) r = m;
            else l = m;
        }
        return r;
    }
};

void solve()
{
    int n, m; cin >> n >> m;
    SegTree st(n);
    while (m--) {
        int k; cin >> k;
        if (k == 1) {
            int a, f; cin >> a >> f; ++a;
            int zeros = st.getZeroCnt(a, n);
            if (zeros == 0) {
                cout << "Can not put any one." << endl;
                continue;
            }
            int start = st.findZero(a, 1);
            int end = st.findZero(a, min(zeros, f));
            cout << start - 1 << ' ' << end - 1 << endl;
            st.update(start, end);
        } else if (k == 2) {
            int a, b; cin >> a >> b; ++a; ++b;
            int ones = st.query(a, b);;
            cout << ones << endl;
            st.clear(a, b);
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    cin >> _;   
    while (_--) solve();
    
    return 0;
}