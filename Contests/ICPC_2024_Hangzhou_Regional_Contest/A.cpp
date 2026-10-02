#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

int fa[30];

void init() {
    for (int i = 0; i < 30; ++i) {
        fa[i] = i;
    }
}

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx == ry) {
        return;
    }
    fa[ry] = rx;
}

void solve() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if (s1.size() != s2.size()) {
        cout << "NO" << endl;
        return;
    }
    if (s1.size() != s3.size()) {
        cout << "YES" << endl;
        return;
    }
    init();
    int sz = s1.size();

    for (int i = 0; i < sz; ++i) {
        unite(s1[i] - 'a', s2[i] - 'a');
    }

    string s(sz, '0'), t(sz, '0');
    for (int i = 0; i < sz; ++i) {
        s[i] = find(s1[i] - 'a');
        t[i] = find(s3[i] - 'a');
    }

    if (s == t) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
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
