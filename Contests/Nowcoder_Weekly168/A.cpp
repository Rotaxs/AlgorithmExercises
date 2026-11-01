#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 1; i <= 2 * n; ++i) {
        int x;
        cin >> x;
        if (i & 1) {
            a.push_back(x);
        } else {
            b.push_back(x);
        }
    }
    for (int x : a)
        cout << x << ' ';
    cout << endl;
    for (int x : b)
        cout << x << ' ';
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
