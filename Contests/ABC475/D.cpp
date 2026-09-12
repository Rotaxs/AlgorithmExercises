#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

int mp[26];
bool vis[10];
string s;
vector<char> ch;

bool isPrime(ll x) {
    if (x < 2) return false;
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

bool dfs(int p) {
    if (p == (int)ch.size()) {
        ll x = 0;
        for (char c : s) {
            x = x * 10 + mp[c - 'a'];
        }
        if (isPrime(x)) {
            cout << x << endl;
            return true;
        }

        return false;
    }
    char c = ch[p];
    for (int d = 0; d <= 9; ++d) {
        if (vis[d]) continue;
        if (c == s[0] && d == 0) {
            continue;
        }
        mp[c - 'a'] = d;
        vis[d] = true;

        if (dfs(p + 1)) return true;

        vis[d] = false;
    }
    return false;
}

void solve() {
    cin >> s;
    memset(mp, -1, sizeof mp);
    bool v[26] = {};
    for (char c : s) {
        if (!v[c - 'a']) {
            v[c - 'a'] = true;
            ch.push_back(c);
        }
    }
    if (!dfs(0)) {
        cout << -1 << endl;
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
