#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll qpow(ll a, ll n, ll p)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = ret * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ret;
}

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

ll bsgs(int a, int b, int p)
{
    a %= p; b %= p;
    map<ll, ll> ha;
    int k = sqrt(p) + 1;
    for (int B = 0, val = b; B < k; B++)
    {
        ha[val] = B;
        val = 1LL * val * a % p;
    }
    ll ak = qpow(a, k, p);
    for (int A = 1, val = ak; A <= k; A++)
    {
        if (ha.count(val)) return 1LL * A * k - ha[val];
        val = 1LL * val * ak % p;
    }
    return -1;
}

int inv(int a, int p) { return qpow(a, p - 2, p); }

void solve()
{
    ll p, a, b, x1, t;
    cin >> p >> a >> b >> x1 >> t;
    x1 %= p; t %= p;
    if (x1 == t) { cout << 1 << '\n'; return; };
    if (a == 0)
    {
        if (b == t) cout << 2 << '\n';
        else cout << -1 << '\n';
    }
    else if (a == 1)
    {
        if (b == 0) cout << -1 << '\n';
        else 
        {
            ll res = (1LL * (t - x1 + p) % p) * inv(b, p) % p;
            cout << res + 1 << '\n';
        }
    }
    else
    {
        ll c = b * inv(a - 1, p) % p;
        ll d = (x1 + c) % p;
        ll ch = (t + c) % p;

        if (d == 0)
        {
            cout << -1 << "\n";
            return;
        }

        ll target = ch * inv(d, p) % p;
        ll res = bsgs(a, target, p);

        if (res == -1) cout << -1 << "\n";
        else cout << res + 1 << "\n";
    }
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