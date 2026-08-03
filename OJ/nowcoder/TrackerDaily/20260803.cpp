#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int MAXA = 2e5 + 5;
ull W[MAXA];
ull t[MAXA];

void initHash() {
    uint64_t seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937_64 rng(seed);
    uniform_int_distribution<ull> dist(0, ULLONG_MAX);
    for (int i = 1; i < MAXA; ++i) {
        W[i] = dist(rng);
    }
    for (int i = 1; i < MAXA; ++i) {
        t[i] = t[i - 1] + 2 * W[i];
    }
}

void solve()
{
    initHash();
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    vector<ull> pre(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for (int i = 1; i <= n; ++i) {
        if (a[i] < MAXA) {
            pre[i] = pre[i - 1] + W[a[i]];
        } else {
            pre[i] = pre[i - 1];
        }
    }
    
    while (q--) {
        int l, r; cin >> l >> r;
        int len = r - l + 1;
        if (len & 1) {
            cout << "No\n";
            continue;
        }
        int m = len >> 1;
        if (m >= MAXA) {
            cout << "No\n";
            continue;
        }
        if (pre[r] - pre[l - 1] == t[m]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
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