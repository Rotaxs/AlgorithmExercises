#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> before(n, 1), behind(n, 1), pre(n), suf(n);
    pre[0] = 1, suf[n - 1] = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            before[i] = before[i - 1] + 1;
        }
        pre[i] = max(pre[i - 1], before[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] < a[i + 1]) {
            behind[i] = behind[i + 1] + 1;
        }
        suf[i] = max(suf[i + 1], behind[i]);
    }

    int ans = max(suf[0], pre[n - 1]);
    for (int i = 1; i < n - 1; ++i) {
        ans = max({ans, pre[i - 1], suf[i + 1]});
        if (a[i - 1] < a[i + 1]) {
            ans = max(ans, before[i - 1] + behind[i + 1]);
        }
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
