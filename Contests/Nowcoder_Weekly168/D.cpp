#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s.insert(i);
    }

    ll tot = 0, last;
    int cur = 0;
    for (int i = 0; i < m; ++i) {
        ll d;
        cin >> d;
        cur = (cur + d) % n;

        auto it = s.lower_bound(cur);
        if (it == s.end()) {
            it = s.begin();
        }

        cur = *it;
        last = *it;
        tot += a[last];
        s.erase(it);
    }

    cout << tot << ' ' << last + 1 << endl;
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
