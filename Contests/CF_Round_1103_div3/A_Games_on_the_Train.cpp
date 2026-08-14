#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    int mi = 10, mx = 0;
    for (int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        mi = min(a, mi);
        mx = max(a, mx);
    }
    cout << (mx- mi + 1) << '\n';
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