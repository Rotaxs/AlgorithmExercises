#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

// ====== 9/28 =========

struct BIT {
    int n;
    vector<ll> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int i, int x) {
        while (i <= n) {
            tree[i] += x;
            i += lowbit(i);
        }
    }
    ll query(int i) {
        ll res = 0;
        while (i >= 1) {
            res += tree[i];
            i -= lowbit(i);
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    auto rank = [&](int x) -> int { return lower_bound(b.begin(), b.end(), x) - b.begin() + 1; };

    BIT bt1(b.size()), bt2(b.size());
    vector<int> pre(n), suf(n);

    for (int i = 0; i < n; ++i) {
        int rk = rank(a[i]);
        bt1.add(rk, 1);
        pre[i] = bt1.query(rk - 1);
    }
    for (int i = n - 1; i >= 0; --i) {
        int rk = rank(a[i]);
        bt2.add(rk, 1);
        suf[i] = n - i - bt2.query(rk);
    }

    ll ans = 0;
    for (int j = 0; j < n; ++j) {
        int rk = rank(a[j]);
        ans += 1ll * pre[j] * suf[j];
    }

    cout << ans << endl;
}

// ===========================

// struct BIT {
//     int n;
//     vector<int> tree;
//     BIT(int n) : n(n), tree(n + 1, 0) {
//     }
//     int lowbit(int x) {
//         return x & -x;
//     }
//     void add(int x, ll k) {
//         while (x <= n) {
//             tree[x] += k;
//             x += lowbit(x);
//         }
//     }
//     ll query(int x) {
//         ll res = 0;
//         while (x >= 1) {
//             res += tree[x];
//             x -= lowbit(x);
//         }
//         return res;
//     }
// };

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n + 1);
//     int mx = 0;
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//         mx = max(mx, a[i]);
//     }

//     BIT bt1(mx), bt2(mx);
//     vector<int> pre(n + 1), suf(n + 1);

//     for (int i = 1; i <= n; ++i) {
//         bt1.add(a[i], 1);
//         pre[i] = bt1.query(a[i] - 1);
//     }

//     for (int i = n; i >= 1; --i) {
//         bt2.add(a[i], 1);
//         suf[i] = n - i + 1 - bt2.query(a[i]);
//     }

//     ll ans = 0;
//     for (int i = 1; i <= n; ++i) {
//         ans += 1ll * pre[i] * suf[i];
//     }

//     cout << ans << endl;
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}
