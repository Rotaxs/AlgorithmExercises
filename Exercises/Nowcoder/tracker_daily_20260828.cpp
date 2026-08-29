#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] << endl;
        return;
    }
    vector<int> suf(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = max(suf[i + 1], a[i]);
    }
    int ans = 0;
    int d = max(1, n - k - 1);
    for (int i = 0; i + d < n; ++i) {
        ans = max(ans, a[i] + suf[i + d]);
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
