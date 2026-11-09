#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b - a > d - c || b > d) {
        cout << -1 << endl;
        return;
    }
    cout << (a - b + d - c + d - b) << endl;
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
