#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    set<int> st;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'o') st.insert(i);
    }
    int ans = 0;
    while (!st.empty()) {
        int u = *st.begin();
        for (int v = u; v < n && s[v] == 'o'; v += k) {
            st.erase(v);
        }
        ++ans;
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
