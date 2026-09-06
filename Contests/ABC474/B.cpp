#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    vector<bool> vis(n + 1, false);
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
        if (i > n / 10 * 10) continue;
        int p; cin >> p;
        vis[p] = true;
        if (ok && i % 10 == 0) {
            for (int j = i - 10 + 1; j <= i; ++j) {
                if (!vis[j]) {
                    ok = false;
                }
            }
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
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
