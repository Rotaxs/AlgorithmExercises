#include <bits/stdc++.h>
#include <queue>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;

    priority_queue<int> pqd;
    priority_queue<int, vector<int>, greater<int>> pqx;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (pqx.empty() || pqx.top() <= x)
            pqx.push(x); // 插入
        else
            pqd.push(x);
        // 多的移到大根堆
        while (pqx.size() > 3)
            pqd.push(pqx.top()), pqx.pop();
        // 不够从大根堆补，要求大根堆非空
        while (pqx.size() < 3 && !pqd.empty())
            pqx.push(pqd.top()), pqd.pop();

        if (i >= 3) cout << pqx.top() << endl;
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
