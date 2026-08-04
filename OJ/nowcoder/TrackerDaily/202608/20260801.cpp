#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 5e5 + 10;

int n, q;
ll a[N], c[N];

inline ll lowbit(ll x) { return x & (-x); }

void add(ll i, ll x) {
    for (i; i <= n; i += lowbit(i)) {
        c[i] += x;
    }
    return;
}

ll query(ll x) {
    ll res = 0;
    for (ll i = x; i >= 1; i -= lowbit(i)) {
        res += c[i];
    }
    return res;
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i]);
        add(i + 1, -a[i]);
    }

    ll op, l, r, x;
    for (int i = 1; i <= q; i++) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> x;
            add(l, x);
            add(r + 1, -x);
        }
        else if (op == 2) {
            cin >> x;
            cout << query(x) << endl;
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
