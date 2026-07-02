#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, m; cin >> n >> m;
    int mx = 0;
    while (m--)
    {
        int a, b; cin >> a >> b;
        if (a <= n && b > mx)
            mx = b;
    }
    cout << n - mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    
    return 0;
}