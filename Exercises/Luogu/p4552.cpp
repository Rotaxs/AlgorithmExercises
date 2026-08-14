#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    ll prev, cur, diff, p = 0, q = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1) cin >> prev;
        else
        {
            cin >> cur;
            diff = cur - prev;
            if (diff > 0) p += diff;
            else q -= diff;
            prev = cur;
        }
    }
    cout << max(p, q) << '\n';
    cout << abs(p - q) + 1 << '\n';

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