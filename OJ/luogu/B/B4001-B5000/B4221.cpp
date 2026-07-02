#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

void solve()
{
    ll p, q; cin >> p >> q;
    ll d = gcd(p, q);
    p = p / d; q = q / d;
    if (p & 1 == 0 || q & 1 == 0)
        cout << p * q / 2 * d * d << '\n';
    else 
        cout << (p * q + 1) / 2 * d * d << '\n';
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