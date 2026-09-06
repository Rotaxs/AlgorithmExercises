#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> cnt(m + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        ++cnt[a];
    }

    vector<int> suf(m + 2, 0);
    for (int i = m; i >= 1; --i) {
        suf[i] = suf[i + 1] + cnt[i];
    }

    vector<ll> ans(m + 1, 0);
    for (int k = 1; k <= min(m, 18); ++k) {
        ll mx = 0, C = 1 << k;
        for (int d = 1; d <= m; ++d) {
            for (int j = 1; j * d <= m && j <= C - 1; ++j) {
                mx += suf[j * d];
            }
            if (C * d <= m) {
                mx += cnt[C * d];
            }
            ans[k] = max(ans[k], mx);
            mx = 0;
        }
    }

    for (int k = 1; k <= m; ++k) {
        if (k >= 18) {
            cout << ans[18] << ' ';
            continue;
        }
        cout << ans[k] << ' ';
    }

    cout << endl;
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
