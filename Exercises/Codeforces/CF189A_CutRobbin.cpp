#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int x, y, z;

    int ans = 0;
    for (x = 0; x <= n / a; ++x) {
        for (y = 0; y <= n / b; ++y) {
            int p = n - x * a - y * b;
            if (p < 0) break;
            if (p % c == 0) {
                z = p / c;
                ans = max(ans, x + y + z);
            }
        }
    }

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
