#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

bool vis[N];
int p[N], cnt;
ll phi[N];

void euler(int n)
{
    vis[1] = vis[0] = true;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {   
        if (!vis[i]) { p[++cnt] = i; phi[i] = i - 1; }
        for (int j = 1; j <= cnt && i * p[j] <= n; j++)
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) { phi[i * p[j]] = p[j] * phi[i]; break; }
            phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
    for (int i = 1; i <= n; i++) phi[i] += phi[i - 1];
}

void solve()
{
    int n;
    cin >> n;
    euler(n);
    ll ans = 0;
    for (int l = 1, r; l <= n; l = r + 1)
    {
        r = min(n / (n / l), n);
        ans += (phi[r] - phi[l - 1]) * (n / l) * (n / l);
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