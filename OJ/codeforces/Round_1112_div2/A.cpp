#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n; cin >> n;
    ll L = 0, R = inf;
    for (int i = 1; i <= n; i++) {
        ll a; cin >> a;
        if (i & 1) {
            R = min(R, a);
        } else {
            L = max(L, a);
        }
    }
    if (n == 1) {
        cout << "NO\n";
        return;
    }
    if (n & 1) {
        cout << "NO\n";
    } else {
        cout << (R > L + 1 ? "YES\n" : "NO\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}