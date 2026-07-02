#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
bool vis[N];
int primes[N], cnt;
int mu[N], mup[N];

void mob(int n)
{
    vis[0] = vis[1] = true;
    mu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) { primes[++cnt] = i; mu[i] = -1; }
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++)
        {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0) { mu[i * primes[j]] = 0; break; }
            mu[i * primes[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= n; i++) mup[i] = mup[i - 1] + mu[i];
}

int main()
{

    return 0;
}