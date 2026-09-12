#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct BIT {
    int n;
    vector<ll> tree;
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

void discretization(vector<int>& arr) {
    vector<int> tmp = arr;
    sort(tmp.begin(), tmp.end());
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        arr[i] = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
    }
}

const int N = 1e5 + 10;
const int MOD = 1e8 - 3;
int tmp[N];

void merge(vector<int>& arr, int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        tmp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }
    while (i <= m)
        tmp[k++] = arr[i++];
    while (j <= r)
        tmp[k++] = arr[j++];
    for (int p = l; p <= r; ++p) {
        arr[p] = tmp[p];
    }
}

ll getInversion(vector<int>& arr, int l, int r) {
    if (l == r) {
        return 0;
    }
    int m = l + ((r - l) >> 1);
    ll l_val = getInversion(arr, l, m);
    ll r_val = getInversion(arr, m + 1, r);
    ll m_val = 0;
    for (int i = l, j = m + 1; i <= m && j <= r; ++i) {
        while (j <= r && arr[i] > arr[j]) {
            m_val += m - i + 1;
            ++j;
        }
    }
    merge(arr, l, m, r);
    return (l_val + m_val + r_val) % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    discretization(a);
    discretization(b);

    vector<int> id(b.size());

    for (int i = 0; i < n; ++i) {
        id[b[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        a[i] = id[a[i]];
    }

    ll ans = 0;

    // 分治
    // ans = getInversion(a, 0, n - 1) % MOD;

    // 树状数组
    BIT bt(n);
    for (int i = 0; i < n; ++i) {
        bt.add(a[i] + 1, 1); // 转为 1-index
        ans = (ans + i + 1 - bt.query(a[i] + 1)) % MOD;
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
