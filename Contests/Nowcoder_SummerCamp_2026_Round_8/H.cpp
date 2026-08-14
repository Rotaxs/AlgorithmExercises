#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

// const int inf = 0x3f3f3f3f;
// const ll inf  = 2e18;

const int MOD = 998244353;



void solve()
{
    int n, x; cin >> n >> x;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum = (sum + (a[i] % MOD)) % MOD;
    }
    if (x == 1) {
        cout << sum << endl;
        return;
    }

    i128 q = 0;
    vector<ll> r(n);
    for (int i = 0; i < n; ++i) {
        q += a[i] / x;
        r[i] = a[i] % x;
    }
    sort(r.rbegin(), r.rend());
    for (int i = 0; i < n; ++i) {
        ll need = x - 1 - r[i];
        if (q >= need) {
            q -= need;
            r[i] = 0;
        } else {
            r[i] += (ll)q;
            q = 0;
            break;
        }
    }

    ll ans = q % (x - 1);
    for (int i = 0; i < n; ++i) {
        ans = (ans + r[i]) % MOD;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}