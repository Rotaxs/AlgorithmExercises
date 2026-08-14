#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 5e5 + 10;
const int M = 998244353;
int inv[N], H[N], C[N];

void build(int n, int m)
{
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (ll)(m - m / i) * inv[m % i] % m;

    H[0] = 0;
    H[1] = inv[1];
    for (int i = 2; i <= n; i++) {
        H[i] = (H[i - 1] + inv[i]) % M;
    }

    C[1] = H[n];
    for (int i = 2; i <= n; i++) {
        ll diff = ((H[n - i + 1] - H[i - 1]) % M + M) % M;
        C[i] = (C[i - 1] + diff) % M;
    }
}

void solve()
{
    int n; cin >> n;
    build(n, M);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll a; cin >> a;
        ans = (ans + (a % M * C[i]) % M) % M;
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