#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;

    vector<pair<ll, int>> u(n + 1), v(n + 1);

    for (int i = 1; i <= n; ++i) {
        ll x, y;
        cin >> x >> y;
        u[i] = {x + y, i};
        v[i] = {x - y, i};
    }

    sort(u.begin() + 1, u.end());
    sort(v.begin() + 1, v.end());

    vector<ll> pre1(n + 1, 0), pre2(n + 2, 0);
    ll sum1 = 0, sum2 = 0;

    for (int i = 1; i <= n; ++i) {
        sum1 += u[i].first;
        pre1[i] = pre1[i - 1] + u[i].first;
        sum2 += v[i].first;
        pre2[i] = pre2[i - 1] + v[i].first;
    }

    vector<ll> cost(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cost[u[i].second] += sum1 + (2 * i - n) * u[i].first - 2 * pre1[i];
        cost[v[i].second] += sum2 + (2 * i - n) * v[i].first - 2 * pre2[i];
    }

    ll ans = 1e18;
    for (int i = 1; i <= n; ++i) {
        ll part1 = sum1 + sum2;
        ans = min(ans, cost[i] / 2);
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
