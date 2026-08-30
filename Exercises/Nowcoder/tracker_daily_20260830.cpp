#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<ll> pre(n + 5, 0), suf(n + 5, 0);
    pre[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        pre[i] = max(0LL, a[i] - pre[i - 1] - pre[i - 2]);
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] += pre[i - 1];
    }
    suf[n] = a[n];
    for (int i = n - 1; i >= 1; --i) {
        suf[i] = max(0LL, a[i] - suf[i + 1] - suf[i + 2]);
    }
    for (int i = n - 1; i >= 1; --i) {
        suf[i] += suf[i + 1];
    }
    ll ans = -1;
    for (int i = 1; i < n; ++i) {

        if (ans == -1) {
            ans = (ll)pre[i - 1] + suf[i + 2];
            continue;
        }
        ans = min(ans, (ll)pre[i - 1] + suf[i + 2]);
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
