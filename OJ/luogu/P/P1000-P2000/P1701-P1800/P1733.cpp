#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int g;
    int l = 0, r = 1e9 + 1;
    while ((l + 1) != r)
    {
        int m = l + ((r - l) >> 1);
        cout << m << endl;
        cin >> g;
        if (g == 0) return;
        else if (g == -1) l = m;
        else r = m;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();
    
    return 0;
}