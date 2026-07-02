#include <bits/stdc++.h>
#define int long long
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int m; cin >> m;
    int mx = 0, zero = 0;
    bool one = false;
    for (int i = 1; i <= m; ++i)
    {
        int a; cin >> a;
        if (a == 1)
        {
            if (one) 
            {
                mx += (zero - 1) >> 1;
            }
            else
            {
                mx += zero >> 1;
                one = true;
            }
            zero = 0;
        }
        else
        {
            zero++;
        }
    }
    mx += zero >> 1;
    int n; cin >> n;

    // cout << mx << endl;
    
    if (mx >= n) cout << "true\n";
    else cout << "false\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    
    return 0;
}