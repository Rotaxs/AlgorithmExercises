#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e4 + 10;

bool vis[N];
int p[N], cnt, mu[N], mu_sum[N];

void euler(int n)
{
    vis[1] = vis[0] = true;
    mu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) { p[++cnt] = i; mu[i] = -1; }
        for (int j = 1; j <= cnt && i * p[j] <= n; j++)
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) { mu[i * p[j]] = 0 ;break;}
            mu[i * p[j]] = -mu[i];
        }
    }
    mu_sum[0] = 0;
    for (int i = 1; i <= n; i++) mu_sum[i] = mu_sum[i - 1] + mu[i];
}

ll calc(int a, int b, int k)
{
    int A = a / k, B = b / k;
    int m = min(A, B);
    ll ans = 0;
    for (int l = 1, r; l <= m; l = r + 1)
    {
        int l1 = A / l, l2 = B / l;
        r = min({A / l1, B / l2, m});
        ans += 1LL * (mu_sum[r] - mu_sum[l - 1]) * (A / l) * (B / l);
    }
    return ans;
}

void solve()
{
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    ll s1 = calc(b, d, k);
    ll s2 = calc(b, c - 1, k);
    ll s3 = calc(a - 1, d, k);
    ll s4 = calc(a - 1, c - 1, k);
    ll ans = s1 - s2 - s3 + s4;
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    euler(N);

    int t;
    cin >> t;
    while (t--) solve();

    // solve();
    
    return 0;
}