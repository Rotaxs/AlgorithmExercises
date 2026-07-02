#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef __int128_t int128;

ll power(ll a, ll b, ll m)
{
    ll res = 1;
    a %= m;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (ll)((int128)res * a % m);
        a = (ll)((int128)a * a % m);
        b /= 2;
    }
    return res;
}

bool miller_rabin(ll n, ll a)
{
    if (power(a, n - 1, n) != 1)
        return false; // 违反费马小定理
    ll d = n - 1;
    while (d % 2 == 0)
    {
        d /= 2;
        ll tmp = power(a, d, n);
        if (tmp == n - 1)
            return true; // 满足二次探测定理的“合数变素数”路径
        if (tmp != 1)
            return false; // 既不是 1 也不是 n-1，必为合数
    }
    return true;
}

bool is_prime(ll n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0)
        return false;
    static const vector<ll> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    for (ll a : bases)
    {
        if (n == a)
            return true;
        if (!miller_rabin(n, a))
            return false;
    }
    return true;
}