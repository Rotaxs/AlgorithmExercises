#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1, 0);
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
        int b;
        cin >> b;
        int pos = b + 1 + n - i;
        if (pos < 1 || pos > n || p[pos] != 0) {
            ok = false;
            continue;
        }
        p[pos] = i;
    }

    if (!ok) {
        cout << -1 << endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        cout << p[i] << ' ';
    }
    cout << endl;
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
