#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, m; cin >> n >> m;
    
    function<int(int, int)> ans = [&](int n, int m) {
        if (m == 0) {
            return n;
        }
        if (n <= 3) {
            return n - m;
        }
        return ans((int)ceil(sqrt(n)), m - 1);
   };

    cout << ans(n, m) << endl;
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
