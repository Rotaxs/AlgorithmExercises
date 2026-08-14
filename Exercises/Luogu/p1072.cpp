#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    return (!b ? a : gcd(b, a % b));
}

void solve()
{
    int a0, a1, b0, b1;
    cin >> a0 >> a1 >> b0 >> b1;
    int ans = 0;
    for (ll x = 1; x * x <= b1; x++)
    {
        if (b1 % x == 0)
        {
            auto check = [&](ll x)
            {
                if (x % a1 != 0) return false;
                if (gcd(x / a1, a0 / a1) != 1) return false;
                if (gcd(b1 / b0, b1 / x) != 1) return false;
                return true;
            };
            if (check(x)) ans++;
            if (x * x != b1 && check(b1 / x)) ans++;   
        }

    }
    cout << ans << '\n';
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