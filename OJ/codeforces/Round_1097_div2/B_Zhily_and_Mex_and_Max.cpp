#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1)
    { 
        if (a[1] == 0)
            cout << 1 << '\n';
        else
            cout << a[1] << '\n'; 
        return; 
    }
    sort(a.begin() + 1, a.end());
    int sz = unique(a.begin() + 1, a.end()) - a.begin() - 1;
    if (a[n] == 0)
    {
        cout << n << '\n';
        return;
    }
    ll ans = 1ll * n * a[sz];
    int cur = 0;
    for (int i = 1; i <= sz - 1; i++)
    {
        if (a[i] == cur) cur++;
        if (a[sz] == cur) cur++;
        ans += cur;
    }
    ans += 1ll * (n - sz) * cur;
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while (t--) solve();
    
    return 0;
}