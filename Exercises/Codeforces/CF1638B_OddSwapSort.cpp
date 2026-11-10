#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    bool ok = true;
    int lastOdd = -1, lastEven = -1;
    while (n--) {
        int a;
        cin >> a;
        if (a & 1) {
            if (lastOdd > a) {
                ok = false;
            }
            lastOdd = a;
        } else {
            if (lastEven > a) {
                ok = false;
            }
            lastEven = a;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
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
