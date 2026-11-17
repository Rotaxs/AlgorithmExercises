#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> val(*max_element(a.begin(), a.end()) + 1, 0);
    for (int &x : a) {
        int v = 0;
        for (int i = 1; 1ll * i * i <= x; ++i) {
            if (x % i == 0) {
                v = max({v, val[i], val[x / i]});
            }
        }
        val[x] = max(v + 1, val[x]);
    }
    cout << *max_element(val.begin(), val.end()) << endl;
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
