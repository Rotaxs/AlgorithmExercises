#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int cnt1 = 0, cnt2 = 0;
    for (char c : s1) {
        if (c == '0') {
            ++cnt1;
        } else {
            ++cnt2;
        }
    }

    for (char c : s2) {
        if (c == '0') {
            ++cnt1;
        } else {
            ++cnt2;
        }
    }

    cout << cnt1 << ' ' << cnt2 << endl;
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
