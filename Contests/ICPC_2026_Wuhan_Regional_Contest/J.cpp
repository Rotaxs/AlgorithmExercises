#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using pii = array<int, 2>;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    map<int, int> cntA, cntB;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cntA[a[i]];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        ++cntB[b[i]];
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    sort(b.begin(), b.end(), [&](int b1, int b2) { return b1 - cntB[b1] < b2 - cntB[b2]; });

    vector<int> rem;
    int free = 0;
    for (int i = 0; i < (int)b.size(); ++i) {
        if (free + cntB[b[i]] >= b[i]) {
            free += cntB[b[i]];
        } else {
            rem.push_back(b[i]);
        }
    }

    for (int i = 0; i < (int)rem.size(); ++i) {
        if (!cntA.count(rem[i]) || cntA[rem[i]] < cntB[rem[i]]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
