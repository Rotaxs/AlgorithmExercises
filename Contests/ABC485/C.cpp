#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 1e8;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> pre(n + 1, inf), suf(n + 1, inf);
    for (int i = 2; i <= n; ++i) {
        if (a[i] != a[i - 1]) pre[i] = 1;
        else pre[i] = pre[i - 1] + 1;
    }
    for (int i = n - 1; i >= 1; --i) {
        if (a[i] != a[i + 1]) suf[i] = 1;
        else suf[i] = suf[i + 1] + 1;
    }

    for (int i = 1; i <= n; ++i) {
        cout << min(pre[i], suf[i]) << ' ';
    }
    cout << endl;
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
