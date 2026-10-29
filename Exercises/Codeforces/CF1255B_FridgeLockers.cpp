#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 1e8;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    int minn1 = inf, minn2 = inf;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (a[i] <= minn1) {
            minn2 = minn1;
            minn1 = a[i];
        } else if (a[i] < minn2) {
            minn2 = a[i];
        }
    }

    if (n <= 2 || n > m) {
        cout << -1 << endl;
        return;
    }

    ll ans = 2 * sum + (m - n) * (minn1 + minn2);
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        if (i == n) {
            cout << i << ' ' << 1 << endl;
        } else {
            cout << i << ' ' << i + 1 << endl;
        }
    }
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
