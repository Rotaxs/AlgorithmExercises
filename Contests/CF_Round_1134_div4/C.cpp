#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n <= 2) {
        cout << n << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
        return;
    }

    sort(a.begin(), a.end());

    vector<int> ans;
    vector<bool> vis(n, false);
    int cnt = 0;

    for (int i = 0; i < n;) {
        ans.push_back(a[i]);
        ++cnt;
        vis[i] = true;
        int j = i + 1;
        while (j < n && a[j] == a[i]) {
            ++j;
        }
        i = j;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (vis[i]) continue;
        if (a[i] != ans.back()) ++cnt;
        ans.push_back(a[i]);
    }

    if (a[n - 1] == a[n - 2]) {
        ++cnt;
    }

    cout << cnt << endl;
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << endl;
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
