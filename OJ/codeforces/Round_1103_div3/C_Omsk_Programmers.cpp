#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll qpow(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1) res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

void solve()
{
    int a, b, x; cin >> a >> b >> x;
    int ans = 1e9;
    int i_max = 0, j_max = 0;
    int tmp_a = a, tmp_b = b;
    while (tmp_a)
    {
        tmp_a /= x;
        i_max++;
    }
    while (tmp_b)
    {
        tmp_b /= x;
        j_max++;
    }
    for (int i = 0; i <= i_max; i++)
    {
        for (int j = 0; j <= j_max; j++)
        {
            ans = min(1ll * ans, abs(a / qpow(x, i) - b / qpow(x, j)) + i + j);
        }
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