#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> cnt(n + 1);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }

    int sum = 0;
    int ans = 0;

    for (int i = 0; i <= n; ++i) {
        if (cnt[i] == 0) break;
        sum += cnt[i];
        if (sum < k) break;
        sum -= k;
        ++ans;
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
