#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

// const int inf = 0x3f3f3f3f;
// const ll inf  = 2e18;

void solve()
{
    ll x, y; cin >> x >> y;
    if (x == 0 || x == 1 || y == 0) {
        cout << -1 << endl;
        return;
    }
    int k = 0;
    while (y >= x) {
        y /= x;
        ++k;
    }
    cout << k << endl;
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