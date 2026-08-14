#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n; cin >> n;
    vector<int> l(n + 1), r(n + 1), u(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i] >> u[i] >> v[i];
    }
    function<bool(int)> check = [&](int m) {
        int j = 1, len = 0;
        for (int i = 1; i <= n; i++) {
            if ((j < l[i] || j > r[i]) && (m - j + 1 < u[i] || m - j + 1 > v[i])) {
                j++;
                len++;
            }
            if (len == m) return true;
        }
        return false;
    };
    int ans = 0;
    for (int m = 1; m <= n; m++) {
        if (check(m)) ans = m;
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