#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    ll x, y, s, m, k, n;
    cin >> x >> y >> s >> m >> k >> n;

    vector<int> a(n + 1), a1, a2;
    a1.push_back(0);
    a2.push_back(0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        int b;
        cin >> b;
        if (b == 1) {
            a2.push_back(a[i]);
        } else {
            a1.push_back(a[i]);
        }
    }

    sort(a1.begin() + 1, a1.end(), greater<int>());
    sort(a2.begin() + 1, a2.end(), greater<int>());

    int len1 = a1.size(), len2 = a2.size();

    vector<ll> pre1(len1 + 1), pre2(len2 + 1);

    for (int i = 1; i < len1; ++i) {
        pre1[i] = pre1[i - 1] + a1[i];
    }
    for (int i = 1; i < len2; ++i) {
        pre2[i] = pre2[i - 1] + a2[i];
    }

    ll ans = 0;
    ll maxP = min({(ll)len1 - 1, m / k, s / (k * x)});

    for (int p = 0; p <= maxP; ++p) {
        int q = min({(s - k * x * p) / (k * x + y), m / k - p, (ll)len2 - 1});
        ans = max(ans, pre1[p] + pre2[q]);
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
