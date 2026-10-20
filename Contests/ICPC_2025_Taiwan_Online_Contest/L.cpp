#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    double xl, yl, xr, yr;
    double x1, y1, x2, y2;
    cin >> xl >> yl >> xr >> yr;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2) {
        bool hit = xl <= x1 && x1 <= xr && max(yl, min(y1, y2)) <= min(yr, max(y1, y2));
        cout << (hit ? "STOP" : "OK") << endl;
        return;
    }

    if (y1 == y2) {
        bool hit = yl <= y1 && y1 <= yr && max(xl, min(x1, x2)) <= min(xr, max(x1, x2));
        cout << (hit ? "STOP" : "OK") << endl;
        return;
    }

    double k = (y1 - y2) / (x1 - x2);
    double b = (x1 * y2 - x2 * y1) / (x1 - x2);

    double L = max(min(x1, x2), min((yr - b) / k, (yl - b) / k));
    double R = min(max(x1, x2), max((yr - b) / k, (yl - b) / k));

    bool hit = (max(xl, L) <= min(xr, R) + 1e-8);
    cout << (hit ? "STOP" : "OK") << endl;
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
