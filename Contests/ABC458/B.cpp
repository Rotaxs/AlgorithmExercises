#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int h, w; cin >> h >> w;
    if (h == 1 || w == 1)
    {
        if (h == 1 && w == 1) cout << 0 << '\n';
        else if (h == 1)
        {
            for (int i = 1; i <= w; i++)
                cout << (i == 1 || i == w ? 1 : 2) << ' ';
        }
        else
        {
            for (int i = 1; i <= h; i++)
                cout << (i == 1 || i == h ? 1 : 2) << '\n';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (
                (i == 1 && j == 1) ||
                (i == 1 && j == w) ||
                (i == h && j == 1) ||
                (i == h && j == w)
            )
                cout << 2 << ' ';
            else if (i == 1 || j == 1 || i == h || j == w)
                cout << 3 << ' ';
            else 
                cout << 4 << ' ';
        }
        cout << '\n';
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