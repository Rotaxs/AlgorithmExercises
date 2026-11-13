#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<pair<int, int>> rgs;

    int l = 0, r = n - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            int a = s[l] - 'a', b = s[r] - 'a';
            if (a > b) {
                swap(a, b);
            }
            rgs.push_back({a, b});
        }
        ++l;
        --r;
    }

    sort(rgs.begin(), rgs.end());

    int ans = 0;
    int L = 0, R = 0;
    for (auto [a, b] : rgs) {
        if (a > R) {
            ans += b - a;
            L = a;
            R = b;
        } else if (b > R) {
            ans += b - R;
            R = b;
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
