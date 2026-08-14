#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 40010;
bool vis[N];
int primes[N], cnt;
int phi[N];
int mu[N], mup[N];

void euler(int n)
{
    vis[0] = vis[1] = true;
    phi[1] = 1;
    mu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) 
        { 
            primes[++cnt] = i;
            phi[i] = i - 1; 
            mu[i] = -1;
        }
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++)
        {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0)
            {
                phi[i * primes[j]] = primes[j] * phi[i]; 
                mu[i * primes[j]] = 0;
                break; 
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
            mu[i * primes[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= n; i++) mup[i] = mup[i - 1] + mu[i];
}

// 莫比乌斯反演解法
void solve()
{
    int n;
    cin >> n;
    euler(n - 1);
    if (n == 1) { cout << 0 << '\n'; return; }
    ll ans = 0;
    for (int l = 1, r, k; l <= n - 1; l = r + 1)
    {
        k = (n - 1) / l;
        r = (n - 1) / k;
        ans += k * k * (mup[r] - mup[l - 1]);
    }
    ans += 2;
    cout << ans << '\n';
}

// 欧拉函数解法
// void solve()
// {
//     int n;
//     cin >> n;
//     if (n == 1) { cout << 0 << '\n'; return; }
//     euler(n);
//     ll ans = 0;
//     for (int i = 1; i <= n - 1; i++)
//         ans += phi[i];
//     ans = 2 * ans + 1;
//     cout << ans << '\n';
// }

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