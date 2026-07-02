#include <iostream>
using namespace std;

int euler(int n)
{
    int ans = n;
    for (int p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            ans = ans / p * (p - 1);
            while (n % p == 0)
                n /= p;
        }
    }
    if (n != 1) ans = ans / n * (n - 1);
    return ans;
}

const int N = 1e5 + 10;
bool vis[N];
int primes[N], cnt;
int phi[N];

void get_phi(int n)
{
    vis[0] = vis[1] = true;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) { primes[++cnt] = i; phi[i] = i - 1; }
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++)
        {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0) { phi[i * primes[j]] = phi[i] * primes[j]; break; }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
}


int main()
{
    // cout << euler(10) << endl;
    get_phi(100);
    for (int i = 2; i <= 100; i++)
    {
        cout << euler(i) << ' ' << phi[i] << '\n';
    }
    return 0;
}