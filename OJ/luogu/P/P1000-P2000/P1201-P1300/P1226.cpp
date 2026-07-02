#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll a, b, p;
    cin >> a >> b >> p;
    ll tmp_a = a, tmp_b = b;
    ll ans = 1;
    while (tmp_b)
    {
        if (tmp_b & 1)
            ans = ans * tmp_a % p;
        tmp_a = tmp_a * tmp_a % p;
        tmp_b >>= 1;
    }
    cout << a << "^" << b << " mod " << p << "=" << ans << '\n';
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