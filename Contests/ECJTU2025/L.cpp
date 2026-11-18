#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = array<int, 2>;

const int inf = 2e9;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<pii> seg(n + 1);
    stack<int> st;
    for (int i = 1; i <= n; ++i) {
        while (!st.empty() && a[i] <= a[st.top()]) st.pop();
        if (!st.empty()) seg[i][0] = st.top();
        else seg[i][0] = 0;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n; i >= 1; --i) {
        while (!st.empty() && a[i] >= a[st.top()]) st.pop();
        if (!st.empty()) seg[i][1] = st.top();
        else seg[i][1] = n + 1;
        st.push(i);
    }

    vector<int> minR(n + 2, inf);
    for (int i = 1; i <= n; ++i) {
        minR[seg[i][0]] = min(minR[seg[i][0]], seg[i][1]);
    }
    for (int i = n; i >= 1; --i) {
        minR[i] = min(minR[i + 1], minR[i]);
    }

    while (q--) {
        int l, r; cin >> l >> r;
        cout << (minR[l] <= r ? "Yes" : "No") << endl;
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
