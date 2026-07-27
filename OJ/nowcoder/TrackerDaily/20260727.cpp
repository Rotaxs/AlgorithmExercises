#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        int pos = upper_bound(a.begin() + 1, a.end(), a[i]) - a.begin() - 1;
        cnt += n - pos;
    }
    ll ans = cnt % MOD * (1ll * n * (n - 1) / 2) % MOD;
    for (int i = 1; i <= n - 2; i++) ans = ans * i % MOD;
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