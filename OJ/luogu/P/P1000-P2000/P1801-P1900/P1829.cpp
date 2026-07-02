#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e7 + 10;
const int MOD = 20101009;

bool vis[N];
int p[N], cnt;
ll f[N], F[N];

void euler(int n)
{
    vis[0] = vis[1] = true;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) { p[++cnt] = i; f[i] = ((1 - i) % MOD + MOD) % MOD; }
        for (int j = 1; j <= cnt && i * p[j] <= n; j++)
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) { f[i * p[j]] = f[i]; break;}
            f[i * p[j]] = (f[i] * f[p[j]]) % MOD;
        }
    }
    F[0] = 0;
    for (int i = 1; i <= n; i++) F[i] = (F[i - 1] + i * f[i] % MOD) % MOD;
}   

void solve()
{
    int n, m; cin >> n >> m;
    int limit = min(n, m);
    euler(limit);
    ll ans = 0;
    for (int l = 1, r; l <= limit; l = r + 1)
    {
        int k1 = n / l, k2 = m / l;
        r = min({n / k1, m / k2, limit});
        ll t1 = ((F[r] - F[l - 1]) % MOD + MOD) % MOD;
        ll t2 = (ll)(1 + k1) * k1 / 2 % MOD;
        ll t3 = (ll)(1 + k2) * k2 / 2 % MOD;
        ans = (ans % MOD + (t1 * t2 % MOD * t3) % MOD) % MOD;
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