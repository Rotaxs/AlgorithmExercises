#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i] || t[i] == '*') {
            continue;
        }
        ok = false;
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
