#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

ll qpow(ll a, ll n, ll p)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1)
            ret = ret * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ret;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll exbsgs(ll a, ll b, ll p)
{
    a %= p;
    b %= p;
    if (b == 1 || p == 1)
        return 0;
    if (a == 0)
        return b == 0 ? 1 : -1;
    int d = gcd(a, p);
    ll k = 1, cnt = 0;
    while (d > 1)
    {
        if (b % d != 0)
            return -1;
        cnt++;
        b /= d;
        p /= d;
        k = k * (a / d) % p;
        if (k == b)
            return cnt;
        d = gcd(a, p);
    }
    ll m = sqrt(p) + 1;
    unordered_map<ll, ll, custom_hash> mp;
    mp.reserve(m);
    for (ll B = 0, val = b; B < m; B++)
    {
        mp[val] = B;
        val = val * a % p;
    }
    int am = qpow(a, m, p);
    for (ll A = 1, val = am * k % p; A <= m; A++)
    {
        if (mp.count(val))
            return A * m - mp[val] + cnt;
        val = val * am % p;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        int a, p, b;
        cin >> a >> p >> b;
        if (a == 0 && p == 0 && b == 0)
            break;
        int ans = exbsgs(a, b, p);
        if (ans == -1)
            cout << "No Solution\n";
        else
            cout << ans << '\n';
    }
    // solve();

    return 0;
}