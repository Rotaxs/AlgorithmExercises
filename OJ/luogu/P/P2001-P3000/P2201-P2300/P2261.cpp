#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// nk - sum(i * (k / i))

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll ans = n * k;
    for (ll l = 1, r, p; l <= n; l = r + 1)
    {
        p = k / l;
        if (p != 0) r = min(n, k / p);
        else r = n;
        ans -= p * (r + l) * (r - l + 1) / 2;
    }
    cout << ans << '\n';
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