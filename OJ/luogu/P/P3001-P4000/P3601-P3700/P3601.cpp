#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
const int MOD = 666623333;
ll l, r;
bool vis[N];
int primes[N], cnt;
ll phi[N], rem[N];

void euler(int n)
{
    vis[0] = vis[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) primes[++cnt] = i;
        for (int j = 1; j <= cnt && (ll)i * primes[j] <= n; j++)
        {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void get_phi()
{
    // 初始化 phi[i - l] = i，即公式中的 n
    for (ll i = l; i <= r; i++)
        phi[i - l] = rem[i - l] = i;
    for (int i = 1; i <= cnt; i++)
    {
        ll p = primes[i];
        if (p * p > r) break;
        ll start = max(p * p, (l + p - 1) / p * p);
        for (ll j = start; j <= r; j += p)
        {
            phi[j - l] = phi[j - l] / p * (p - 1);
            while (rem[j - l] % p == 0) rem[j - l] /= p;
        }
    }
    for (ll i = l; i <= r; i++)
    {
        if (rem[i - l] > 1)
            phi[i - l] = phi[i - l] / rem[i - l] * (rem[i - l] - 1);
    }
}

void solve()
{
    cin >> l >> r;
    euler(N - 1);
    get_phi();
    ll ans = 0;
    for (ll i = l; i <= r; i++)
    {
        ans = (ans + (i - phi[i - l]) % MOD) % MOD;
    }
    cout << ans << '\n';
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