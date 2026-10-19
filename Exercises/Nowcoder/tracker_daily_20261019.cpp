#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<char> st(n + 1);
    int l = 0, r = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (l >= r || st[r - 1] != c) {
            st[r++] = c;
            continue;
        }
        while (l < r && st[r - 1] == c) {
            --r;
            ans += 2;
        }
    }

    while (l < r && l + 1 != r && st[l] == st[r - 1]) {
        ++l;
        --r;
        ans += 2;
    }

    cout << ans << endl;
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
