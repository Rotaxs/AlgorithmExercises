#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        pos[b[i]] = i;
    }

    int last = 0;
    bool ok = true;

    for (int i = 1; i <= n; ++i) {
        int c;
        cin >> c;
        if (c == 0) continue;
        if (pos[a[i]] < last) {
            ok = false;
        }
        last = pos[a[i]];
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
