#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 9901;

ll qpow(ll a, ll n)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return ret;
}

int inv(int n)
{
    return qpow(n, MOD - 2);
}

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == 0)
    {
        cout << 0 << '\n';
        return;
    }
    ll ans = 1;
    for (ll i = 2; i <= a / i; i++)
    {
        if (a % i == 0)
        {
            int e = 0;
            while (a % i == 0)
            {
                e++;
                a /= i;
            }
            ll sum;
            if (i % MOD == 1)
            {
                sum = ((ll)b * e + 1) % MOD;
            }
            else
            {
                sum = (qpow(i, (ll)b * e + 1) - 1 + MOD) % MOD;
                sum *= inv(i - 1) % MOD;
            }
            ans = (ans * sum) % MOD;
        }
    }
    if (a > 1) 
    {
        ll sum;
        if (a % MOD == 1)
        {
            sum = (b + 1) % MOD;
        }
        else
        {
            sum = (qpow(a, b + 1) - 1 + MOD) % MOD;
            sum = sum * inv(a - 1) % MOD;
        }
        ans = ans * sum % MOD;
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