#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}
void solve() {
    int x, y, l, r;
    cin >> x >> y >> l >> r;

    int g = gcd(x, y);
    int a = x / g, b = y / g;

    int L = max((l + a - 1) / a, (l + b - 1) / b);
    int R = min(r / a, r / b);

    int ans = max(0, R - L + 1);

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
