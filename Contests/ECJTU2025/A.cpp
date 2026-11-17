#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int d = 1, p1 = 1, p2 = 1;
    int x = 0, y = 0;
    int n = 16;
    for (int i = 1; i <= 16; ++i) {
        if (i % 2) {
            x += d;
        } else {
            y += d;
        }
        if (i >= 2) {
            d = p1 + p2;
            p2 = p1;
            p1 = d;
        }
    }
    cout << x << ' ' << y << endl;
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
