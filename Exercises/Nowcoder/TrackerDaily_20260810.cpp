#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<ll> pre(n + 2, inf), suf(n + 2, inf);
    for (int i = 1; i <= n; ++i) { 
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        pre[i] = min(pre[i + 1], 1ll * a[i] * i);
    }
    for (int i = 1; i <= n; ++i) {
        suf[i] = min(suf[i - 1], 1ll * a[i] * (n - i + 1));
    }
    ll ans = inf;
    pre[0] = 0; suf[n + 1] = 0;

    // set<int> st;
    // for (int l = 1, r = 1; r <= n; ++r) {
    //     while (l <= r && st.count(a[r])) {
    //         st.erase(a[l++]);
    //     }
    //     st.insert(a[r]);
    //     ans = min(ans, pre[l - 1] + suf[r + 1]);
    // }

    unordered_map<int, int> lastSeen;
    for (int l = 1, r = 1; r <= n; ++r) {
        if (lastSeen.count(a[r])) {
            l = max(l, lastSeen[a[r]] + 1);
        }
        lastSeen[a[r]] = r;
        ans = min(ans, pre[l - 1] + suf[r + 1]);
    }

    cout << ans << endl;
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