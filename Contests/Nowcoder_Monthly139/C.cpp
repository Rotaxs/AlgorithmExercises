#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, x;
    cin >> n >> x;
    int sum = 0;
    ll ans = 0;
    vector<ll> c(n + 1);
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    if (x == 1 && n % 2 == 0) {
        cout << -1 << endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        pq.push(c[i]);

        if (++sum > (x + i) / 2) {
            ans += pq.top();
            pq.pop();
            --sum;
        }
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
