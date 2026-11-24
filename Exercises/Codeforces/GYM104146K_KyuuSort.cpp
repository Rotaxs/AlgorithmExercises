#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    string ans;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (p[j] > p[j + 1]) {
                swap(p[j], p[j + 1]);
                ans += 'S';
            }
            ans += 'P';
        }
        ans += 'P';
    }

    cout << (ans.empty() ? "empty" : ans) << endl;
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
