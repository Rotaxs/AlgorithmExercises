#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

const int MOD = 998244353;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    ll ans = 0;
    ll p10 = 1;
    ll rem = 10 % m;
    for (int l = 1; l <= 19; l++)
    {
        ll L_bound = p10, R_bound;
        if (p10 > n / 10) R_bound = n;
        else R_bound = min(n, p10 * 10 - 1);
        if (L_bound > R_bound) break; 

        ll cnt_y = (R_bound - L_bound + 1) % MOD;
        ll g = gcd((rem - 1 + m) % m, m);
        ll step = m / g;
        ll cnt_x = (n / step) % MOD;
        ll cur_ans = (cnt_x * cnt_y) % MOD;
        ans = (ans + cur_ans) % MOD;

        rem = (rem * 10) % m;
        if (l < 19) p10 *= 10;
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while (t--) solve();
    
    return 0;
}