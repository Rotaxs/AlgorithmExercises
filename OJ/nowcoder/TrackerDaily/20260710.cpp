#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int l, r, x; cin >> l >> r >> x;
    bool found = false;
    for (int i = l; i <= r; i++)
    {
        if (i % x == 0)
        {
            found = true;
            cout << i << endl;
            break;
        } 
    }
    if (!found) cout << -1 << endl;
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