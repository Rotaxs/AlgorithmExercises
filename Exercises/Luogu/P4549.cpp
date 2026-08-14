#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }

void solve()
{   
    int n;
    cin >> n;
    int ans = 0;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (i == 0)
        {
            ans = a;
        }
        ans = gcd(ans, a);
    }
    cout << abs(ans) << '\n';
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