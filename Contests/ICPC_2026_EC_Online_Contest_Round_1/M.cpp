#include <bits/stdc++.h>
#include <unordered_map>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

unordered_map<string, int> mp;

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        mp[s]++;
    }
    for (int q = 1; q <= m; ++q) {
        string s;
        cin >> s;
        if (!mp.count(s)) {
            cout << "WRONG" << endl;
        } else {
            if (mp[s] == 1) {
                cout << "OK" << endl;
                ++mp[s];
            } else {
                cout << "REPEAT" << endl;
            }
        }
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
