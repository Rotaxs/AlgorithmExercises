#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int m, d; cin >> m >> d;
    string s; cin >> s;
    vector<bool> sv(m, false);
    for (int i = 0; i < m; i++) {
        if (s[i] == 'G') {
            for (int j = max(0, i - d); j <= min(m - 1, i + d); j++)
                sv[j] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (!sv[i]) ans++;
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