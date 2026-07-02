#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll y, z, p;

int get_phi(int n)
{
    int ret = n;
    for (int p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            ret = ret * (p - 1) / p;
            while (n % p == 0) n /= p;
        }
    }
    if (n != 1) ret = ret * (n - 1) / n;
    return ret;
}

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

int bsgs(ll a, ll b, ll p)
{
    a %= p; b %= p;
    if (b == 1 || p == 1) return 0;
    if (a == 0) return (b == 0) ? 1 : -1;
    unordered_map<ll, ll> mp;
    int k = sqrt(p) + 1;
    for (ll B = 0, val = b; B < k; B++)
    {
        mp[val] = B;
        val = val * a % p;
    }
    ll ak = qpow(a, k, p);
    for (ll A = 1, val = ak; A <= k; A++)
    {
        if (mp.count(val)) return A * k - mp[val];
        val = 1LL * val * ak % p;
    }
    return -1;
}

ll inv(int a, int p)
{
    return qpow(a, p - 2, p);
}

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b) { x = 1; y = 0; return a; }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void solve1()
{
    // int phi = get_phi(p);
    // if (z >= phi) z = z % phi + phi;
    cout << qpow(y, z, p) << '\n';
}

void solve2()
{
    // int d = gcd(y, p);
    // if (z % d != 0) cout << "Orz, I cannot find x!\n";
    if (y % p == 0 && z % p != 0) cout << "Orz, I cannot find x!\n";
    else
    {
        cout << ((z % p) * inv(y, p)) % p << '\n';
    }
    // ll x, l;
    // ll d = exgcd(y, p, x, l);
    // if (z % d != 0) { cout << "Orz, I cannot find x!\n"; return; } 
    // x = x * (z / d);
    // x = (x % (p / d) + p / d) % (p / d);
    // cout << x << '\n';
}

void solve3()
{
    int ans = bsgs(y, z, p);
    if (ans == -1) cout << "Orz, I cannot find x!\n";
    else cout << ans << '\n';
}

void solve(int k)
{
    cin >> y >> z >> p;
    if (k == 1) solve1();
    else if (k == 2) solve2();
    else if (k == 3) solve3();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t, k;
    cin >> t >> k;
    while (t--) solve(k);

    // solve();
    
    return 0;
}