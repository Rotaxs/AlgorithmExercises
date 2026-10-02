#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct Node {
    int id, l, r;
    bool operator<(const Node &other) {
        if (l == other.l) {
            return r < other.r;
        }
        return l < other.l;
    }
};

void solve() {
    int n, f; cin >> n >> f;
    vector<Node> a(n);

    for (int i = 0; i < n; ++i) {
        a[i].id = i;
        cin >> a[i].l >> a[i].r;
    }

    sort(a.begin(), a.end());

    vector<int> ll, rr;
    int L = 0, R = 0;
    for (auto [_,l, r] : a) {
        if (L == 0 && R == 0) {
            L = l;
            R = r;
            continue;
        }
        if (l <= R) {
            R = r;
        } else {
            ll.push_back(L);
            rr.push_back(R);
            L = 0;
            R = 0;
        }
    }
    
    int len = ll.size();

    vector<long long> val(len);
    vector<vector<int>> ids(len, vector<int>());
    int sz = 0;
    for (int i = 0; i < n; ++i) {
        int l = a[i].l, r = a[i].r, id = a[i].id;
        if (l >= ll[sz] && r <= rr[sz]) {
            ids[sz].push_back(id);
            val[sz] += r - l;
        } else {
            ids[++sz].push_back(id);
            val[sz] += r - l;
        }
    }
    
    cout << 1 << endl;

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
