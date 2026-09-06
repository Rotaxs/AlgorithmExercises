#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    ll maxW = 1e18, minW = 1;
    i128 res = 0;
    vector<ll> w(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        ll b; cin >> b;
        a[i] -= b;
        if (a[i] < 0) {
            res += (i128)(w[i] = minW) * a[i];
        } else {
            res += (i128)(w[i] = maxW) * a[i];
        }
    }
    
    if (res > 0) {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; ++i) {
            cout << w[i] << ' ';
        }
    } else {
        cout << "No" << endl;
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
