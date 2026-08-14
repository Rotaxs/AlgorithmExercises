#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int MOD = 998244353;

ll qpow(ll a, ll n, ll p = MOD)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = (ret * a) % p;
        a = (a * a) % p;
        n >>= 1;
    }
    return ret;
}

ll inv(int a, int p = MOD)
{
    return qpow(a, p - 2, p);
}

void solve()
{
    int n; cin >> n;
    vector<bool> is_prime(n + 1, true);
    ll L = 1;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i]) 
        {
            for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
            ll p = i;
            while (p * i <= n) {
                p *= i;
            }
            L = (L * (p % MOD)) % MOD;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll part = (n - 2LL * i + 1) % MOD;
        if (part < 0) part += MOD;
        ll term = (part * L) % MOD;
        term = (term * inv(i)) % MOD;

        ans = (ans + term) % MOD;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    
    return 0;
}