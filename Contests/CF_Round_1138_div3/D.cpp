#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n; cin >> n;
    vector<ll> X(n + 1), Y(n + 1);
    for (int i = 1; i <= n; ++i) cin >> X[i];
    for (int i = 1; i <= n; ++i) cin >> Y[i];
    vector<ll> sufx(n + 2, 0), sufy(n + 2, 0);
    for (int i = n; i >= 1; --i) {
        sufx[i] = sufx[i + 1] + X[i];
        sufy[i] = sufy[i + 1] + Y[i];
    }
    ll a = 0, b = 0;
    bool swapped = false;
    int last = n + 1;
    for (int i = n; i >= 1; --i) {
        ll diff = swapped ? b - a : a - b;
        ll buy = X[i] - Y[i] + diff;
        ll skip = -diff;

        if (buy < skip) {
            swapped = !swapped;
            continue;
        }

        if (!swapped) {
            a += X[i];
            b += Y[i];
        } else {
            a += Y[i];
            b += X[i];
        }
    }

    if (a == b) {
        cout << "Draw" << endl;
        return;
    }

    if ((!swapped && a > b) || (swapped && a < b)) {
        cout << "Sunny" << endl;
    } else {
        cout << "Aubrey" << endl;
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
