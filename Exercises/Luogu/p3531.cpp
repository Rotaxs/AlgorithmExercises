#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

queue<int> pos[26];

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

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < n; ++i) {
        int l = b[i] - 'A';
        pos[l].push(i + 1); // 1-index
    }

    vector<int> arr(n + 1);
    int mx = 0;

    for (int i = 0; i < n; ++i) {
        int l = a[i] - 'A';
        int rk = pos[l].front();
        pos[l].pop();
        mx = max(mx, rk);
        arr[i + 1] = rk;
    }

    BIT bt(mx + 1);
    ll ans = 0;

    for (int i = 1; i <= n; ++i) {
        bt.add(arr[i], 1);
        ans += i - bt.query(arr[i]);
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
