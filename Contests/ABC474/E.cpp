#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll inf = 1e18;

void solve()
{
    int n; cin >> n;
    ll S = 0, M = inf;
    vector<int> diff(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int a, b; cin >> a >> b;
        M = min(1ll * a, M);
        S += a;
        diff[i] = a - b;
    }

    sort(diff.begin() + 1, diff.end(), greater<int>());

    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + diff[i];
    }

    ll ans = inf;
    for (int k = 0; k <= n; ++k) {
        ans = min(ans, S - pre[k] + max(0, 2 * k - n) * M);
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
