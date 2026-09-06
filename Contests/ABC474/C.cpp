#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, q; cin >> n >> q;
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    vector<int> a(q + 1, 0);
    for (int i = 1; i <= q; ++i) {
        cin >> a[i];
    }

    vector<bool> vis(n + 1, false);
    stack<int> st;
    for (int i = q; i >= 1; --i) {
        if (!vis[a[i]]) {
            vis[a[i]] = true;
            st.push(a[i]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[p[i]]) {
            cout << p[i] << ' ';
        }
    }

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    // cin >> _;
    while (_--) solve();
    
    return 0;
}
