#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e7 + 10;
int p[N], cnt;
bool vis[N];
int mu[N], f[N];

void euler(int n)
{   
    vis[0] = vis[1] = true;
    mu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) { p[++cnt] = i; mu[i] = -1; }
        for (int j = 1; j <= cnt && i * p[j] <= n; j++)
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) break;
            mu[i * p[j]] = -mu[i];
        }
    }

    // 不是遍历 n，而是遍历质数（内层遍历指数的倍数，计算当前质数对其倍数的贡献）
    for (int i = 1; i <= cnt; i++)
        for (int j = p[i]; j <= n; j += p[i])
            f[j] += mu[j / p[i]];

    for (int i = 1; i <= n; i++) f[i] += f[i - 1];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int limit = min(n, m);
    ll ans = 0;
    for (int l = 1, r; l <= limit; l = r + 1)
    {
        r = min({limit, n / (n / l), m / (m / l)});
        ans += 1LL * (f[r] - f[l - 1]) * (n / l) * (m / l);
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    euler(N - 1);

    int t;
    cin >> t;
    while (t--) solve();

    
    return 0;
}