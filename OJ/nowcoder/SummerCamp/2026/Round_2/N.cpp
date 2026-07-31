#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n, k; cin >> n >> k;
    vector<ll> a(n + 1);
    ll sum = 0;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin() + 1, a.end());

    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];

    int m = (k - 1) / 2;
    int rem = k - m;
    ll ans = 0;
    ll sum_m = pre[m];
    
    for (int i = m + 1; i + rem - 1 <= n; i++)
    {
        ll mid = 0;
        if (k % 2 != 0)
            mid = (ll)k * a[i];
        else
            mid = (ll)(k / 2) * (a[i] + a[i + 1]);
        ll cur = sum - (sum_m + pre[i + rem - 1] - pre[i - 1]) + mid;
        ans = max(ans, cur);
    }

    cout << ans << '\n';
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