#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    map<char, string> mp = {
        {'A', "la"},
        {'B', "si"},
        {'C', "do"},
        {'D', "re"},
        {'E', "mi"},
        {'F', "fa"},
        {'G', "sol"}
    };
    string s; cin >> s;
    bool f = false;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        int j = n - i - 1;
        if (s[i] == s[j]) {
            if (f) cout << endl;
            f = false;
        }
        else {
            cout << mp[s[i]];
            f = true;
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
