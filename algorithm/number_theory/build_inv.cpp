#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1010;
int inv[N];
int fact[N];
int invFact[N];

void build_inv(int n, int m)
{
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (ll)(m - m / i) * inv[m % i] % m;
}

void build_invFact(int n, int m)
{
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % m;
    invFact[n] = qpow(fact[n], m - 2, m);
    for (int i = n - 1; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % m;
}

int main()
{

    return 0;
}