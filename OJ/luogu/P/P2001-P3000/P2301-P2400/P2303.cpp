#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// const int N = (1 << 16) + 10;
// bool vis[N];
// int primes[N], cnt;
// int phi[N];

// void euler(int n)
// {
//     vis[0] = vis[1] = true;
//     phi[1] = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         if (!vis[i])
//         {
//             primes[++cnt] = i;
//             phi[i] = i - 1;
//         }
//         for (int j = 1; j <= cnt && i * primes[j] <= n; j++)
//         {
//             vis[i * primes[j]] = true;
//             if (i % primes[j] == 0)
//             {
//                 phi[i * primes[j]] = primes[j] * phi[i];
//                 break;
//             }
//             phi[i * primes[j]] = phi[i] * (primes[j] - 1);
//         }
//     }
// }

ll get_phi(ll x)
{
    ll ans = x;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ans = ans * (i - 1) / i;
            while (x % i == 0) x /= i;
        }
    }
    if (x != 1) ans = ans * (x - 1) / x;
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    // euler(n);
    ll ans = 0;
    ll d = 1;
    for (; d * d < n; d++)
    {
        if (n % d == 0)
            // ans += phi[n / d] * d + phi[d] * (n / d);
            ans += get_phi(n / d) * d + get_phi(d) * (n / d);
    }
    if (d * d == n) ans += get_phi(d) * d;
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