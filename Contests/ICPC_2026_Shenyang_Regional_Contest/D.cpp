#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, a, b, k; cin >> n >> a >> b >> k;
    if (a + b > n + 1 || (n > 1 && a == 1 && b == 1)) {
        cout << -1 << endl;
        return;
    }
    if (b > 1) {
        if (k <= a) cout << n - a + k << endl;
        else {
            if (k - a < b - 1) cout << n - k + 1 << endl;
            else if (k - a == b - 1) cout << 1 << endl;
            else cout << n - k + 2 << endl;
        }
    } else {
        if (k == 1) cout << 1 << endl;
        else if (k <= a) cout << n - a + k << endl;
        else cout << n - k + 2 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}
