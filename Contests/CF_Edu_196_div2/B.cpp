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

    sort(a.begin(), a.end());
    map<int, bool> vis;
    vector<pair<int, int>> cnt;

    for (int i = 0; i < n; ++i) {
        if (vis[a[i]]) continue;
        int c = 1;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] % a[i] == 0) {
                ++c;
            }
        }
        cnt.push_back({a[i], c});
    }

    int rem = 0;
    for (auto [x, c] : cnt) {
        if (c > rem) {
            rem = c;
        }
    }

    cout << n - rem << endl;
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
