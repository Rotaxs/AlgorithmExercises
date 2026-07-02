#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, m;
string b;

int get_phi(int n)
{
    int ret = n;
    for (int p = 2; 1LL * p * p <= n; p++)
    {
        if (n % p == 0)
        {
            ret = ret / p * (p - 1);
            while (n % p == 0) n /= p;
        }
    }
    if (n > 1) ret = ret / n * (n - 1);
    return ret;
}

ll qpow(ll a, ll n)
{
    int ret = 1;
    while (n)
    {
        if (n & 1) ret = ret * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return ret;
}

int get_b(int phi)
{
    int ret = 0;
    bool ok = false;
    for (char c : b)
    {
        ret = ret * 10 + (c - '0');
        if (ret >= phi) ok = true, ret %= phi;
    }
    if (ok) ret += phi;
    return ret;
}

void solve()
{
    cin >> a >> m >> b;
    int phi = get_phi(m);
    int b = get_b(phi);
    cout << qpow(a, b) << '\n';
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