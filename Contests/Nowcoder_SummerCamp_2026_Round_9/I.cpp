#include <bits/stdc++.h>
#define endl '\n'
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x)  << " (Line " << __LINE__ << ")" << endl
#else
#define debug(x)
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

const int inf = 1e9;

void solve()
{
    int x, a, b; cin >> x >> a >> b;

    auto calc = [&](ll p, ll k) -> i128 {
        i128 t = min((i128)k - p, (i128)p * a - p);
        i128 part1 = (i128)p * (a + p * a - p + 1) / 2;
        i128 part2 = ((i128)2 * p * a - 2 * p - t + 1) * t / 2;
        i128 part3 = (i128)(k - p) * b;
        return part1 + part2 + part3;
    };

    auto check = [&](ll k) -> bool {
        ll test[] = {0, k, k / a, k - b / a, k - b / a + 1};
        i128 mx = 0;
        for (ll p : test) {
            if (p >= 0 && p <= k) {
                mx = max(mx, calc(p, k));
            }
        }
        return mx >= x;
    };

    int l = 0, r = 1e9 + 10;
    while ((l + 1) != r) {
        ll m = l + ((r - l) >> 1);
        if (check(m)) r = m;
        else l = m;
    }
    cout << r << endl;
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