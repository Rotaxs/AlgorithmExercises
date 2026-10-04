#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, k;
    cin >> n >> k;
    if ((n + 1) / 2 < k) {
        cout << "No" << endl;
        return;
    }

    vector<int> p1, p2;
    for (int i = n; i >= 1; --i) {
        if (k > 0 && ((n ^ i) & 1) == 0) {
            p1.push_back(i);
            --k;
        } else {
            p2.push_back(i);
        }
    }

    cout << "Yes" << endl;
    for (int x : p1) {
        cout << x << ' ';
    }
    for (int x : p2) {
        cout << x << ' ';
    }
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
