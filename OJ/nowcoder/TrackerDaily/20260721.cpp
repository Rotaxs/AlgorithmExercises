#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n, m; cin >> n >> m;
    int mx = 0;
    while (m--)
    {
        int a, b; cin >> a >> b;
        if (a <= n)
            mx = max(mx, b);
    }
    cout << n - mx << endl;
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