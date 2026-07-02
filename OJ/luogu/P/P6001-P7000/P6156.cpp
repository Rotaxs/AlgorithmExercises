#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;
const int N = 10000005;

int n;
ll k;
bool vis[N];
int p[700000], cnt;
int f[N], F[N], pk[N], s1[N], s2[N];

ll qpow(ll a, ll n)
{
    ll ret = 1;
    a %= MOD;
    while (n)
    {
        if (n & 1)
            ret = ret * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return ret;
}

void euler(int limit)
{
    vis[0] = vis[1] = true;
    f[1] = 1;
    pk[1] = 1;
    for (int i = 2; i <= limit; i++)
    {
        if (!vis[i])
        {
            p[++cnt] = i;
            f[i] = i - 1;
            pk[i] = qpow(i, k);
        }
        for (int j = 1; j <= cnt && 1LL * i * p[j] <= limit; j++)
        {
            int target = i * p[j];
            vis[target] = true;
            pk[target] = 1LL * pk[i] * pk[p[j]] % MOD;
            if (i % p[j] == 0)
            {
                if ((i / p[j]) % p[j] != 0)
                {
                    f[target] = 1LL * (MOD - p[j]) * f[i / p[j]] % MOD;
                }
                else
                {
                    f[target] = 0;
                }
                break;
            }
            f[target] = 1LL * f[i] * f[p[j]] % MOD;
        }
    }
    for (int i = 1; i <= limit; i++)
    {
        int val_h = 1LL * f[i] * pk[i] % MOD;
        F[i] = (F[i - 1] + val_h);
        if (F[i] >= MOD)
            F[i] -= MOD;

        s1[i] = (s1[i - 1] + pk[i]);
        if (s1[i] >= MOD)
            s1[i] -= MOD;

        s2[i] = (s2[i - 1] + 1LL * i * pk[i] % MOD);
        if (s2[i] >= MOD)
            s2[i] -= MOD;
    }
}

inline ll get_S(int m)
{
    ll part1 = (s2[m + 1] - s1[m + 1] + MOD) % MOD;
    ll sum_s1 = (s1[2 * m] - s1[m + 1] + MOD) % MOD;
    ll sum_s2 = (s2[2 * m] - s2[m + 1] + MOD) % MOD;
    ll part2 = (1LL * (2 * m + 1) * sum_s1 % MOD - sum_s2 + MOD) % MOD;
    ll res = part1 + part2;
    return res >= MOD ? res - MOD : res;
}

void solve()
{
    if (!(cin >> n >> k))
        return;
    euler(2 * n);
    ll ans = 0;
    for (int l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ll deltaF = (F[r] - F[l - 1] + MOD) % MOD;
        ans = (ans + get_S(n / l) * deltaF) % MOD;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}