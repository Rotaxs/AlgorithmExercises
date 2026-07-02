#include <bits/stdc++.h>
using namespace std;

using ll = long long;   

void solve()
{
    int n, k; cin >> n >> k;
    while (k--)
    {
        int x, y; cin >> x >> y;
        string s; cin >> s;
        int dx = 0, dy = 0;
        for (char c : s)
        {
            if (c == 'f')
            {
                if (y + 1 <= n) y++;
            }
            else if (c == 'b')
            {
                if (y - 1 >= 1) y--;
            }
            else if (c == 'l')
            {
                if (x - 1 >= 1) x--;
            }
            else
            {
                if (x + 1 <= n) x++;
            }
        }
        cout << x << ' ' << y << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}