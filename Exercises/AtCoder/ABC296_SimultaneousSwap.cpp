#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct BIT {
    int n;
    vector<ll> tree;
    BIT(int n) : n(n), tree(n + 1) {
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int i, ll v) {
        while (i <= n) {
            tree[i] += v;
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

int getParityOfInversion(const vector<int>& a) {
    int n = (int)a.size() - 1;
    vector<bool> vis(n + 1, false);

    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (vis[u]) continue;
        ++cnt;
        int v = u;
        while (!vis[v]) {
            vis[v] = true;
            v = a[v];
        }
    }
    return (n - cnt) & 1;
}

int getInversion(const vector<int>& a) {
    int n = (int)a.size() - 1;
    BIT bt(n);
    ll ret = 0;
    for (int i = 1; i <= n; ++i) {
        bt.add(a[i], 1);
        ret += i - bt.query(a[i]);
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    // int aInv = getInversion(a);
    // int bInv = getInversion(b);
    int aParity = getParityOfInversion(a);
    int bParity = getParityOfInversion(b);

    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());

    if (a != b) {
        cout << "No" << endl;
        return;
    }

    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i + 1]) {
            cout << "Yes" << endl;
            return;
        }
    }

    // if ((aInv + bInv) % 2 == 0) {
    //     cout << "Yes" << endl;
    // } else {
    //     cout << "No" << endl;
    // }

    cout << ((aParity + bParity) % 2 == 0 ? "Yes" : "No") << endl;
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
