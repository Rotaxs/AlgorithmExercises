#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    string s; cin >> s;
    int n = s.size();
    string ans;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c == '-') {
            if (!ans.empty()) ans.pop_back();
            continue;
        }
        int sz = ans.size();
        if (sz == 0) ans.push_back(c);
        else if (sz == 1) {
            if (ans.back() != c) ans.push_back(c);
        } else if (sz == 2) {
            if (ans[0] != c && ans[1] != c) ans.push_back(c);
        } else {
            if (ans[sz - 1] != c && ans[sz - 2] != c) ans.push_back(c);
        }
    }

    if (ans.empty()) cout << '-' << endl;
    else cout << ans << endl;
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
