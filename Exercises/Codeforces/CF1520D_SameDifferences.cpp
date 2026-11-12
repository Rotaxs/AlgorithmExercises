#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> cnt;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        ++cnt[a - i];
    }

    ll ans = 0;
    for (auto [_, c] : cnt) {
        ans += 1ll * c * (c - 1) / 2;
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
