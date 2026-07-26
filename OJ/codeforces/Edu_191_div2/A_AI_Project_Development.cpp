#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, x, y, z; cin >> n >> x >> y >> z;
    int res1 = (n - x * z + x + 10 * y - 1) / (x + 10 * y) + z;
    int res2 = (n + x + y - 1) / (x + y);
    cout << min(res1, res2) << '\n';
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