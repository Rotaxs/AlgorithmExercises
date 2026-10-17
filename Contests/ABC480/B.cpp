#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct Info {
    string name;
    int votes;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Info> ans;
    int id = 0;
    for (int i = 1; i <= n; ++i) {
        string name;
        cin >> name;
        ans.push_back({name, 0});
    }

    auto getDiff = [&](const string& a, const string& b) -> int {
        int diff = 0;
        int len = a.size();
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) ++diff;
        }
        return diff;
    };

    auto findMostMatch = [&](const string& t) -> int {
        int p = -1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            string name = ans[i].name;
            if (name.size() != t.size()) continue;
            int d = getDiff(name, t);
            if (d == 0) return i;
            if (d == 1) {
                p = i;
                ++cnt;
            }
        }
        return (cnt == 1 ? p : -1);
    };

    for (int i = 1; i <= m; ++i) {
        string name;
        cin >> name;
        int pos = findMostMatch(name);
        if (pos != -1) {
            ++ans[pos].votes;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i].votes << endl;
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
