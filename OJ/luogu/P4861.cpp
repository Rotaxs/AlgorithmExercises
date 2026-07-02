#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// BSGS 解法

int gcd(int a, int b) { return !b ? a : gcd(b, a % b);}

ll pow(ll a, ll n, ll p)
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

ll bsgs(int a, int b, int p)
{
    int k = ceil(sqrt(p));
    unordered_map<int, int> ha;
    for (int B = 0, val = b % p; B < k; B++)
    {
        ha[val] = B;
        val = 1LL * val * a % p;
    }
    ll ak = pow(a, k, p);
    for (int A = 1, val = ak; A <= k; A++)
    {
        if (ha.count(val)) return 1LL * A * k - ha[val];
        val = 1LL * val * ak % p;
    }
    return -1;
}

void solve()
{
    int m, k;
    cin >> m >> k;
    int ans = bsgs(k, 1, m);
    if (ans == -1) cout << "Let's go Blue Jays!";
    else cout << ans << '\n';

}

// 欧拉定理解法
// ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

// int get_phi(ll n)
// {
//     int ret = n;
//     for (ll p = 2; p <= n / p; p++)
//     {
//         if (n % p == 0)
//         {
//             ret = ret / p * (p - 1);
//             while (n % p == 0) { n /= p; }
//         }
//     }
//     if (n != 1) ret = ret / n * (n - 1);
//     return ret;
// }

// ll qpow(ll a, ll n, int m)
// {
//     ll ret = 1;
//     while (n)
//     {
//         if (n & 1) ret = ret * a % m;
//         a = a * a % m;
//         n >>= 1;
//     }
//     return ret;
// }

// void solve()
// {
//     ll m, k; cin >> m >> k;
//     if (gcd(k, m) != 1) { cout << "Let's go Blue Jays!\n"; return; }
//     int phi = get_phi(m);
//     vector<ll> divisors;

//     for (ll i = 1; i * i <= phi; i++)
//     {
//         if (phi % i == 0)
//         {
//             divisors.push_back(i);
//             if (i * i != phi)
//                 divisors.push_back(phi / i);
//         }
//     }

//     sort(divisors.begin(), divisors.end());

//     for (ll d : divisors)
//     {
//         if (qpow(k, d, m) == 1)
//         {
//             cout << d << endl;
//             return;
//         }
//     }
// }

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