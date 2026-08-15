#include <bits/stdc++.h>
#define endl '\n'
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x)  << " (Line " << __LINE__ << ")" << endl
#else
#define debug(x)
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;

// struct segtree {
//     int n;
//     vector<int> arr, tree, addVal;

//     segtree(int size) {
//         n = size;
//         arr.resize(n + 1);
//         tree.resize((n + 1) << 2, 0);
//         addVal.resize((n + 1) << 2, 0);
//     }
//     void read() {
//         for (int i = 1; i <= n; ++i) {
//             cin >> arr[i];
//         }
//         build(1, 1, n);
//     }
//     void pushUp(int p) {
//         tree[p] = min(tree[p << 1], tree[p << 1 | 1]);
//     }
//     void pushDown(int p, int l, int r) {
//         if (addVal[p]) {
//             tree[p << 1] += addVal[p];
//             addVal[p << 1] = addVal[p];
//             addVal[p << 1 | 1] = addVal[p];
//             addVal[p << 1 | 1] += addVal[p];
//             addVal[p] = 0;
//         }
//     }
//     void build(int p, int l, int r) {
//         if (l == r) {
//             tree[p] = arr[l];
//             return;
//         }
//         int m = l + ((r - l) >> 1);
//         build(p << 1, l, m);
//         build(p << 1 | 1, m + 1, r);
//         pushUp(p);
//     }
//     int query(int ql, int qr, int p, int l, int r) {
//         if (ql <= l && r <= qr) {
//             return tree[p];
//         }
//         pushDown(p, l, r);
//         int ans = 2e9;
//         int m = l + ((r - l) >> 1);
//         if (ql <= m) ans = min(ans, query(ql, qr, p << 1, l, m));
//         if (qr > m) ans = min(ans, query(ql, qr, p << 1 | 1, m + 1, r));
//         return ans;
//     }
//     void add(int ql, int qr, int v, int p, int l, int r) {
//         if (ql <= l && r <= qr) {
//             tree[p] += v;
//             addVal[p] = v;
//             return;
//         }
//         pushDown(p, l, r);
//         int m = l + ((r - l) >> 1);
//         if (ql <= m) add(ql, qr, v, p << 1, l, m);
//         if (qr > m) add(ql, qr, v, p << 1 | 1, m + 1, r);
//         pushUp(p);
//     }
//     int query(int l, int r) {
//         return query(l, r, 1, 1, n);
//     }
//     void add(int l, int r, int v) {
//         add(l, r, v, 1, 1, n);
//     }
//     void add(int i, int v) {
//         add(i, i, v);
//     }
// };


// void solve()
// {
// 	int h, w, n; 
//     while (cin >> h >> w >> n) {
//         h = min(h, n);
//         segtree st(n); st.build(1, 1, n);

//         auto search = [&](int x) -> int {
//             int l = 0, r = h + 1;
//             while ((l + 1) != r) {
//                 int m = l + ((r - l) >> 1);
//                 if (x <= w - st.query(1, m)) r = m;
//                 else l = m;
//             }
//             return r;
//         };

//         for (int i = 0; i < n; ++i) {
//             int pw; cin >> pw;
//             int ans = search(pw);
//             if (ans == h + 1) {
//                 cout << -1 << endl;
//             } else {
//                 cout << ans << endl;
//                 st.add(ans, pw);
//             }
//         }
//     }
// }

struct segtree {
    int n;
    vector<int> arr, tree;

    segtree(int size) {
        n = size;
        arr.resize(n + 1);
        tree.resize((n + 1) << 2, 0);
    }
    void pushUp(int p) {
        tree[p] = min(tree[p << 1], tree[p << 1 | 1]);
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
    void add(int i, int v, int p, int l, int r) {
        if (l == r) {
            tree[p] += v;
            return;
        }
        int m = l + ((r - l) >> 1);
        if (i <= m) add(i, v, p << 1, l, m);
        else add(i, v, p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    int query(int limit, int p, int l, int r) {
        if (tree[p] > limit) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int m = l + ((r - l) >> 1);
        if (tree[p << 1] <= limit) return query(limit, p << 1, l, m);
        return query(limit, p << 1 | 1, m + 1, r);
    }
    
    int query(int limit) {
        return query(limit, 1, 1, n);
    }

    void add(int i, int v) {
        add(i, v, 1, 1, n);
    }
};

void solve()
{
    int h, w, n;
    while (cin >> h >> w >> n) {
        h = min(h, n);
        segtree st(h);
        st.build(1, 1, h);
        for (int i = 0; i < n; ++i) {
            int pw; cin >> pw;
            int ans = st.query(w - pw);
            cout << ans << endl;
            if (ans != -1) st.add(ans, pw);
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