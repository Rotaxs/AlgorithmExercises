#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), cnt(m + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    
    vector<int> suf(m + 2, 0);
    for (int i = m; i >= 1; --i) {
        suf[i] = suf[i + 1] + cnt[i];
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int c = suf[i];
        if ((i << 1) <= m) c += cnt[i << 1];
        ans = max(ans, c);
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
