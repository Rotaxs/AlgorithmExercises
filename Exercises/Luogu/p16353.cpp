#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    if (n == 1)
    {
        if (x != y) cout << "NO\n";
        else cout << "YES\n";
        return;
    }
    if (x == 0 || y == 0)
    {
        cout << "YES\n";
    }
    if (x > 0 && y < 0)
    {
        cout << "YES\n";
    }
    if (x > 0 && y > 0)
    {
        if (x >= n * y) cout << "YES\n";
        else cout << "NO\n";
    }
    if (x < 0 && y < 0)
    {
        if (y <= x * n) cout << "YES\n";
        else cout << "NO\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();

    // solve();
    
    return 0;
}