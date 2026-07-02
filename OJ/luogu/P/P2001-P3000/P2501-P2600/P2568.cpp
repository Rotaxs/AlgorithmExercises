#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e7 + 10;
int primes[N], cnt;
bool vis[N];
int phi[N];

void euler(int n)
{
    vis[0] = vis[1] = true;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            primes[++cnt] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++)
        {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0)
            {
                phi[i * primes[j]] = primes[j] * phi[i];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    euler(n);
    ll ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        int p = primes[i];
        for (int k = 1; k <= n / p; k++)
        {
            if (k != 1) ans += phi[k] * 2;
            else ans += phi[k];
        }
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