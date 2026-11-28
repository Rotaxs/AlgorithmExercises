#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int l, a, b; cin >> l >> a >> b;
    vector<bool> vis1(l, false), vis2(l, false);
    int c = 0;
    while (!vis1[c]) {
        vis1[c] = true;
        c = (c + a) % l;
    }
    c = 0;
    while (!vis2[c]) {
        vis2[c] = true;
        c = (c + b) % l;
    }
    int ans = 0;
    for (int i = 0; i < l; ++i) {
        if (vis1[i] && vis2[i]) ++ans;
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
