#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<bool> onField(101, false);
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        onField[a] = true;
    }
    while (m--) {
        int x, y; cin >> x >> y;
        onField[x] = false;
        onField[y] = true;
    }

    for (int i = 1; i <= 101; ++i) {
        if (onField[i]) {
            cout << i << ' ';
        }
    }
    cout << endl;
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
