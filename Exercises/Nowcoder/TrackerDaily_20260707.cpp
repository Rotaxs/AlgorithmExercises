#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 5e6 + 10;
int cnt[70];

void solve()
{
    int n; cin >> n;
    vector<ll> a(n + 1);
    ll all_or = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        all_or |= a[i];
        for (int v = 0; v < 63; v++)
            if (((a[i] >> v) & 1)) cnt[v]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll tmp = all_or;
        for (int v = 0; v < 63; v++)
        {
            if (!((a[i] >> v) & 1)) continue;
            if (cnt[v] > 1) continue;
            tmp &= ~(1ll << v);
        }
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    
    return 0;
}