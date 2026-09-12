#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    int a = 0, b = 0, c = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        int pay = 0;
        if (x % 1000 == 0) {
            pay = x;
        } else {
            pay = (x / 1000 + 1) * 1000;
        }

        int diff = pay - x;
        a += diff / 100;
        b += diff % 100 / 10;
        c += diff % 10;
    }

    cout << c << ' ' << b << ' ' << a << endl;
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
