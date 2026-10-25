#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    int minn = 2e9;

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        minn = min(minn, a);
    }

    cout << (minn < n ? n : 0) << endl;
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
