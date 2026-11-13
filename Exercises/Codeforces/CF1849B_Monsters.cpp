#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct Node {
    int id, v;
    bool operator<(const Node& other) const {
        if (v == other.v) {
            return id < other.id;
        }
        return v > other.v;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<Node> a(n);
    // for (int i = 0; i < n; ++i) {
    //     int x;
    //     cin >> x;
    //     a[i] = {i + 1, x % k};
    // }
    // sort(a.begin(), a.end());
    // int start;
    // for (start = n - 1; start >= 0; --start) {
    //     if (a[start].v != 0) break;
    // }
    // ++start;
    // for (int i = start; i < n; ++i) {
    //     cout << a[i].id << ' ';
    // }
    // for (int i = 0; i < start; ++i) {
    //     cout << a[i].id << ' ';
    // }

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = {i + 1, (x - 1) % k + 1};
    }
    sort(a.begin(), a.end());

    for (auto [id, _] : a) {
        cout << id << ' ';
    }

    cout << endl;
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
