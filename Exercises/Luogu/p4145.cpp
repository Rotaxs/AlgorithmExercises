#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

// const int inf = 0x3f3f3f3f;
// const ll inf  = 2e18;

struct SegTree {
    int n;
    vector<ll> arr, sum, maxn;
    SegTree(int size) {
        n = size;
        arr.resize(n + 1, 0);
        sum.resize((n + 1) << 2, 0);
        maxn.resize((n + 1) << 2, 0);
    }
    void read() {
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        build(1, 1, n);
    }
    void build(int p, int l, int r) {
        if (l == r) {
            sum[p] = arr[l];
            maxn[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m);
        build(p << 1 | 1, m + 1, r);
        pushUp(p);
    }

    void pushUp(int p) {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
        maxn[p] = max(maxn[p << 1], maxn[p << 1 | 1]);
    }

    void update(int ql, int qr, int p, int l, int r) {
        if (l == r) {
            int res = sqrt(sum[p]);
            sum[p] = res;
            maxn[p] = res;
            return;
        }
        int m = (l + r) >> 1;
        if (ql <= m && maxn[p << 1] > 1) update(ql, qr, p << 1, l, m);
        if (qr > m && maxn[p << 1 | 1] > 1) update(ql, qr, p << 1 | 1, m + 1, r);
        pushUp(p);
    }

    ll query(int ql, int qr, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            return sum[p];
        }
        ll ans = 0;
        int m = (l + r) >> 1;
        if (ql <= m) ans += query(ql, qr, p << 1, l, m);
        if (qr > m) ans += query(ql, qr, p << 1 | 1, m + 1, r);
        return ans;
    }

    void update(int l, int r) {
        update(l, r, 1, 1, n);
    }

    ll query(int l, int r) {
        return query(l, r, 1, 1, n);
    }
};

void solve()
{
    int n; cin >> n;
    SegTree st(n); st.read();
    int m; cin >> m;
    while (m--) {
        int k, l, r; cin >> k >> l >> r;
        if (l > r) swap(l, r);
        if (k == 0) {
            st.update(l, r);
        } else if (k == 1) {
            cout << st.query(l, r) << endl;
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