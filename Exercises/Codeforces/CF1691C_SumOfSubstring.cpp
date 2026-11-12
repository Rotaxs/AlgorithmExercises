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

    if (s[n - 1] == '0') {
        int i;
        for (i = n - 1; i >= 0; --i) {
            if (s[i] == '1') break;
        }
        if (i >= 0 && k >= n - 1 - i) {
            swap(s[i], s[n - 1]);
            k -= n - 1 - i;
        }
    }

    if (s[0] == '0') {
        int i;
        for (i = 1; i < n - 1; ++i) {
            if (s[i] == '1') break;
        }
        if (i < n - 1 && k >= i) {
            swap(s[0], s[i]);
            k -= i;
        }
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += (s[i] - '0') * 10 + s[i + 1] - '0';
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
