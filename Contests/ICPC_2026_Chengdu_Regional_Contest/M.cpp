#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    int maxR = -2e9, premax, ans = 0;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        if (i == 0) {
            premax = r;
            maxR = r;
            ++ans;
            continue;
        }

        maxR = max(maxR, r);

        if (premax < l) {
            premax = maxR;
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
