#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

void solve() {
    ll n, k;
    cin >> n >> k;
    i128 part1 = k * n;
    i128 part2 = 0;
    ll limit = min(n, k);

    for (ll l = 1, r, v; l <= limit; l = r + 1) {
        v = k / l;
        r = min(limit, k / v);
        part2 = part2 + (i128)(l + r) * (r - l + 1) / 2 * v;
    }

    ll ans = part1 - part2;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}
