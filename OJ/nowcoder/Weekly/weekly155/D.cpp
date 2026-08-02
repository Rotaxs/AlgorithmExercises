#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n, m; cin >> n >> m;
    int len = 1 << m;
    vector<int> cnt(len, 0);
    for (int i = 0; i < n; ++i) {
        int num = 0;
        for (int j = 0; j < m; ++j) {
            char ch; cin >> ch;
            int v = ch - '0';
            num = 2 * num + v;
        }
        cnt[num]++;
    }
    ll ans = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (i & j) {
                ans += 1LL * cnt[i] * cnt[j];
            }
        }
        if (cnt[i] > 1) {
            ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
        }
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