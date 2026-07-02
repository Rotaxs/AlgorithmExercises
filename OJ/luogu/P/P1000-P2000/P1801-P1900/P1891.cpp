#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

bool vis[N];
int p[N], cnt, phi[N];
ll ans[N];

void euler(int n)
{
    vis[0] = vis[1] = true;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) { p[++cnt] = i; phi[i] = i - 1; }
        for (int j = 1; j <= cnt && i * p[j] <= n; j++)
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) { phi[i * p[j]] = p[j] * phi[i]; break;}
            phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << n * ans[n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    euler(N - 1);

    for (int i = 1; i <= N - 1; i++) ans[i] = 1;
    for (int d = 2; d <= N - 1; d++)
    {
        for (int a = d; a <= N - 1; a += d)
        {
            ans[a] += (ll)d * phi[d] / 2;
        }
    }

    int t;
    cin >> t;
    while (t--) solve();

    // solve();
    
    return 0;
}