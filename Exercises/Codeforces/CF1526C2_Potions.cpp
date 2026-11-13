#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    ll sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a < 0) {
            pq.push(a);
        }
        sum += a;
        ++ans;
        if (sum < 0) {
            sum -= pq.top();
            pq.pop();
            --ans;
        }
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
