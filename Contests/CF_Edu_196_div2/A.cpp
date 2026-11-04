#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int l, r;
    cin >> l >> r;
    if (l == r) {
        cout << 0 << endl;
        return;
    }

    if (l == 0) {
        cout << r - 1 << endl;
    } else if (l > 0) {
        cout << r - l << endl;
    } else {
        if (r < 0) {
            cout << r - l << endl;
        } else if (r == 0) {
            cout << -l - 1 << endl;
        } else {
            if (l + r == 0) {
                cout << 0 << endl;
            } else {
                cout << abs(l + r) - 1 << endl;
            }
        }
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
