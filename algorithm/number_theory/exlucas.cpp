#include <iostream>
using namespace std;

typedef long long ll;

ll qpow(ll a, ll b, ll m)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

ll get_inv(ll a, ll m)
{
    ll x, y;
    exgcd(a, m, x, y);
    return (x % m + m) % m;
}

// 计算 n! 中不包含质因子 p 的部分对 pk 取模的结果
// 即：n! / (p^x) % pk
ll fac(ll n, ll p, ll pk)
{
    if (!n)
        return 1;
    ll res = 1;
    for (ll i = 1; i <= pk; i++)
    {
        if (i % p)
            res = res * i % pk;
    }
    res = qpow(res, n / pk, pk);
    for (ll i = 1; i <= n % pk; i++)
    {
        if (i % p)
            res = res * i % pk;
    }
    return res * fac(n / p, p, pk) % pk;
}

// 计算 C(n, m) % pk
ll C_pk(ll n, ll m, ll p, ll pk)
{
    if (m < 0 || m > n) return 0;
    ll k = 0;
    // 统计分子分母中质因子 p 的总指数差
    for (ll i = n; i; i /= p) k += i / p;
    for (ll i = m; i; i /= p) k -= i / p;
    for (ll i = n - m; i; i /= p) k -= i / p;

    ll a = fac(n, p, pk);
    ll b = fac(m, p, pk);
    ll c = fac(n - m, p, pk);

    return a * get_inv(b, pk) % pk * get_inv(c, pk) % pk * qpow(p, k, pk) % pk;
}

ll a[100], mod[100], cnt;
ll CRT()
{
    ll M = 1, ans = 0;
    for (int i = 1; i <= cnt; i++)
        M *= mod[i];
    for (int i = 1; i <= cnt; i++)
    {
        ll m = M / mod[i];
        ans = (ans + a[i] * m % M * get_inv(m, mod[i]) % M) % M;
    }
    return (ans + M) % M;
}

// 扩展卢卡斯主函数
ll exLucas(ll n, ll m, ll M)
{
    cnt = 0;
    ll temp = M;
    for (ll i = 2; i * i <= temp; i++)
    {
        if (temp % i == 0)
        {
            ll pk = 1;
            while (temp % i == 0)
                pk *= i, temp /= i;
            mod[++cnt] = pk;
            a[cnt] = C_pk(n, m, i, pk);
        }
    }
    if (temp > 1)
    {
        mod[++cnt] = temp;
        a[cnt] = C_pk(n, m, temp, temp);
    }
    return CRT();
}

int main()
{
    ll n, m, M;
    while (cin >> n >> m >> M)
    {
        cout << exLucas(n, m, M) << endl;
    }
    return 0;
}