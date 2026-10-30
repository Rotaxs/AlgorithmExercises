#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> cntA(n + 1, 0), cntB(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        ++cntA[a[i]];
        ++cntB[b[i]];
    }

    ll ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n; ++i) {
        ans -= 1ll * (cntA[a[i]] - 1) * (cntB[b[i]] - 1);
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
