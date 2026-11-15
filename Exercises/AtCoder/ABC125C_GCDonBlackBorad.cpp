#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> pre(n + 1, 0), suf(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        pre[i] = gcd(pre[i - 1], a[i]);
    }
    for (int i = n; i >= 1; --i) {
        suf[i] = gcd(suf[i + 1], a[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, gcd(pre[i - 1], suf[i + 1]));
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
