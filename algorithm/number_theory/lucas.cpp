#include <iostream>
using namespace std;

typedef long long ll;

const int MAXP = 100005;
ll fac[MAXP], inv[MAXP];

ll qpow(ll a, ll b, ll p)
{
    ll res = 1;
    a %= p;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void init(ll p)
{
    fac[0] = 1;
    for (int i = 1; i < p; i++)
        fac[i] = fac[i - 1] * i % p;
    // 费马小定理求 (p-1)! 的逆元
    inv[p - 1] = qpow(fac[p - 1], p - 2, p);
    // 递推求其他逆元
    for (int i = p - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % p;
}

ll C(ll n, ll m, ll p)
{
    if (m < 0 || m > n) return 0;
    return fac[n] * inv[m] % p * inv[n - m] % p;
}

ll Lucas(ll n, ll m, ll p)
{
    if (m == 0) return 1;
    return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

int main()
{
    // 示例用法
    ll n = 1000000000, m = 500000000, p = 10007;
    init(p); // 必须先初始化
    cout << Lucas(n, m, p) << endl;
    return 0;
}