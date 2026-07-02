#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e8 + 1;
bool is_not_prime[N];
int primes[N >> 1 + 1], cnt = 0;

void euler(int n)
{
    is_not_prime[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!is_not_prime[i])
            primes[cnt++] = i;
        for (int j = 0; j < cnt; j++)
        {
            if (i * primes[j] > n) break;
            is_not_prime[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    euler(n);
    int num;
    while (q--)
    {
        cin >> num;
        cout << primes[num - 1] << '\n';
    }
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