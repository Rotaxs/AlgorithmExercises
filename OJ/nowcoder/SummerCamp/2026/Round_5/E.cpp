#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 1e7 + 10;
const int MOD = 998244353;
int primes[N], cnt, g[N], H[N];
bool is_not_prime[N];

void euler(int n) {
    H[1] = 1;
    is_not_prime[0] = is_not_prime[1] = true;
    for (int i = 2; i <= n; ++i) {
        if (!is_not_prime[i]) { 
            primes[++cnt] = i;
            H[i] = 1;
        }
        for (int j = 1; j <= cnt && i * primes[j] <= n; ++j) {
            is_not_prime[i * primes[j]] = true;
            H[i * primes[j]] = H[i] + 1;
            if (i % primes[j] == 0) break;
        }
    }
}

// ll qpow(ll a, ll n) {
//     ll ret = 1;
//     while (n) {
//         if (n & 1) ret = ret * a % MOD;
//         a = a * a % MOD;
//         n >>= 1;
//     }
//     return ret;
// }

void solve()
{
    int n, c; cin >> n >> c;
    euler(n);
    ll ans = 0;
    g[1] = 1;
    for (int i = 2; i <= n; ++i) {
        g[i] = is_not_prime[i] ? primes[H[i] - 1] : 1;
    }
    ll cpow = c;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + g[i] * cpow % MOD) % MOD;
        cpow = (cpow * c) % MOD;
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    // cin >> _;
    while (_--) solve();
    
    return 0;
}