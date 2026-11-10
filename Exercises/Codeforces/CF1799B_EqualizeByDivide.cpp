#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct Node {
    int id, x;
    bool operator<(const Node& other) const {
        return x < other.x;
    }
};

void solve() {
    int n;
    cin >> n;
    multiset<Node> s;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        s.insert({i, a});
    }

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    auto mx = *prev(s.end()), mi = *s.begin();

    if (mi.x == 1 && mx.x != 1) {
        cout << -1 << endl;
        return;
    }

    vector<array<int, 2>> ans;

    int q = 0;
    while (mi.x != mx.x) {
        s.erase(prev(s.end()));
        int x = (mx.x + mi.x - 1) / mi.x;
        s.insert({mx.id, x});
        ans.push_back({mx.id, mi.id});
        mx = *prev(s.end());
        mi = *s.begin();
        ++q;
    }

    cout << q << endl;
    for (auto [i, j] : ans) {
        cout << i << ' ' << j << endl;
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
