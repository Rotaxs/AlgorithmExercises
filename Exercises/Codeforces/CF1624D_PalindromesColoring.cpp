#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (char& c : s) {
        ++cnt[c - 'a'];
    }
    int p = 0;
    for (int c : cnt) {
        p += c / 2;
    }

    auto check = [&](int x) { return x / 2 * k <= p && k * x <= n; };

    int l = 0, r = n / k + 1;
    while (l + 1 != r) {
        int m = l + ((r - l) >> 1);
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << endl;
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
