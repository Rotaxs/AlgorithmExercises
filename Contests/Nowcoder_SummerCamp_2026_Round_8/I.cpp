#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

// const int inf = 0x3f3f3f3f;
// const ll inf  = 2e18;

#define int ll

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> a(n << 1 | 1);
    for (int i = 1; i <= (n << 1); ++i) {
        cin >> a[i];
    }
    int ans1 = 0, ans2 = 0;
    int pmin = a[1] + m, pmax = a[1];

    if (a[2] > pmin) ++ans1;
    for (int i = 2; i <= n; ++i) {
        int u = a[2 * i - 1], v = a[2 * i];
        if (u > pmin && v > pmin) {
            ans1 += 2;
        } else if (u > pmin || v > pmin) {
            ++ans1;
        } else {
            if (u + v + m > 2 * pmin) {
                ++ans1;
            }
        }
    }

    if (a[2] + m > pmax) ++ans2;
    for (int i = 2; i <= n; ++i) {
        int u = a[2 * i - 1], v = a[2 * i];
        if (u > pmax && v > pmax) {
            ans2 += 2;
        } else if (u > pmax && v <= pmax) {
            if (v + m > pmax) ans2 += 2;
            else ++ans2;
        } else if (u <= pmax && v > pmax) {
            if (u + m > pmax) ans2 += 2;
            else ++ans2;
        } else {
            if (u + v + m > 2 * pmax) ans2 += 2;
            else if (u + m > pmax || v + m > pmax) ++ans2;
        }
    }

    cout << ans1 << ' ' << ans2 << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}