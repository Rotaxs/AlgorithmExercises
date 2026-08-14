#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e4 + 10;

int p[N], cnt, c[N];
bool vis[N];
ll h[N], f[N];

void euler(int n)
{
    vis[0] = vis[1] = true;
    h[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) { p[++cnt] = i; h[i] = 1 - i; }
        for (int j = 1; j <= cnt && i * p[j] <= n; j++)
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) { h[i * p[j]] = h[i]; break; }
            // h[i * p[j]] = h[i] * h[p[j]]
            h[i * p[j]] = h[i] * (1 - p[j]);
        }
    }
}

void solve()
{
    int mx = 0, a, n; cin >> n;
    for (int i = 1; i <= n; i++) { cin >> a; c[a]++; mx = max(mx, a); }
    euler(mx);
    for (int t = 1; t <= mx; t++)
        for (int j = 1; j * t <= mx; j++)
            f[t] += j * c[j * t];
    ll ans = 0;
    for (int i = 1; i <= mx; i++) ans += i * h[i] * f[i] * f[i];
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    
    return 0;
}