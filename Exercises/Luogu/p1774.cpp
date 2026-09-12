// 树状数组

#include <algorithm>
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, ll k) {
        while (x <= n) {
            tree[x] += k;
            x += lowbit(x);
        }
    }
    ll query(int x) {
        ll res = 0;
        while (x >= 1) {
            res += tree[x];
            x -= lowbit(x);
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b.push_back(a[i]);
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    BIT bt(b.size());

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int rank = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        bt.add(rank, 1);
        ans += i - bt.query(rank);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}

// 分治

// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;

// const int N = 5e5 + 10;
// int tmp[N];

// void merge(vector<int>& a, int l, int m, int r) {
//     int i = l, j = m + 1, k = l;
//     while (i <= m && j <= r) {
//         tmp[k++] = a[i] <= a[j] ? a[i++] : a[j++];
//     }
//     while (i <= m)
//         tmp[k++] = a[i++];
//     while (j <= r)
//         tmp[k++] = a[j++];
//     for (int p = l; p <= r; ++p) {
//         a[p] = tmp[p];
//     }
// }

// ll getInversion(vector<int>& a, int l, int r) {
//     if (l == r) {
//         return 0;
//     }
//     int m = (l + r) >> 1;
//     ll l_val = getInversion(a, l, m);
//     ll r_val = getInversion(a, m + 1, r);
//     ll m_val = 0;
//     for (int i = l, j = m + 1; i <= m && j <= r;) {
//         if (a[i] <= a[j]) ++i;
//         while (j <= r && a[i] > a[j]) {
//             m_val += m - i + 1;
//             ++j;
//         }
//     }
//     merge(a, l, m, r);
//     return l_val + m_val + r_val;
// }

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n + 1);
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//     }
//     cout << getInversion(a, 1, n) << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int _ = 1;
//     // cin >> _;
//     while (_--)
//         solve();

//     return 0;
// }
