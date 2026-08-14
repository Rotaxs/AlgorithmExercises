#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int MOD = 1e7 + 7;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0, s = a[n - 1] + a[n - 2];
    for (int i = n - 2; i >= 0 && s >= 0; --i) {
        ans = (ans + s) % MOD;
        if (i - 1 >= 0)
            s = s + a[i - 1];
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