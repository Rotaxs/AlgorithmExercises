#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0, mx = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
        if (a[i] == -1)
            ++cnt;
        else
            sum += a[i];
    }

    int maxCnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == mx) {
            ++maxCnt;
        }
    }

    int left = n - sum;

    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) {
            if (left > mx) cout << i << ' ';
        } else {
            if (maxCnt == 1 && a[i] == mx && (mx - 1) * cnt >= left) cout << i << ' ';
        }
    }
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
