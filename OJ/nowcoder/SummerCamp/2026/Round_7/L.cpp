#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    ll n; cin >> n;
    ll ans = 0;
    for (ll b = 1; b * b <= n; ++b) {
        ll base = b * b + b;
        ll k = (n + b) / base;
        ans += (k - 1) * b;
        ans += min(n, k * base - 1) - (k * base - b) + 1;
    }
    cout << ans << endl;
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