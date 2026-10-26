#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = s + s;

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        string t = "";
        if (i + 7 - 1 >= n + k) break;
        for (int j = 0; j < 7; ++j) {
            t += s[i + j];
        }
        if (t == "nanjing") {
            ++ans;
        }
    }

    cout << ans << endl;
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
