#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

void solve()
{
    ll x1, y1, r1, x2, y2, r2; 
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    ll d_square = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    ll rd = (r1 + r2) * (r1 + r2), rm = (r1 - r2) * (r1 - r2);
    if (d_square <= rd && d_square >= rm)
        cout << "Yes\n";
    else 
        cout << "No\n";

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while (t--) solve();
    
    return 0;
}