#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int n, m;
bool vis[N];
int primes[N], cnt;
int f[N];

void eratosthenes(int n)
{
    vis[1] = vis[0] = true;
    for (int i = 2; i <= n / i; i++)
    {
        if (!vis[i])
            for (int j = i * i; j <= n; j += i)
                vis[j] = true;
    }
}

void euler(int n)
{
    vis[1] = vis[0] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) { primes[++cnt] = i; f[i]++; }
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++)
        {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
    for (int i = 2; i <= n; i++) f[i] += f[i - 1];
}


void solve()
{
    int l, r; cin >> l >> r;
    if (l < 1 || r > m) { cout << "Crossing the line\n"; return; }
    // int cnt = 0;
    // for (int i = l; i <= r; i++)
    //     if (!vis[i]) cnt++;
    // cout << cnt << '\n';
    cout << f[r] - f[l - 1] << '\n';
    // cout << f[10] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // eratosthenes(N);
    euler(N);
    cin >> n >> m;
    while (n--) solve();
    
    return 0;
}