#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = array<int, 2>;

void solve() {
    int n; cin >> n;
    vector<pii> a(4 * n);
    for (int i = 0; i < 4 * n; ++i) {
        char c;
        cin >> a[i][1] >> c;
        if (c == 'R') a[i][0] = 1;
        else if (c == 'Y') a[i][0] = 2;
        else if (c == 'G') a[i][0] = 3;
        else a[i][0] = 4;
    }

    for (int i = 0; i < 4 * n; ) {
        int j = i + 1;
        while (j < 4 * n && a[j][1] == a[i][1]) ++j;
        sort(a.begin() + i, a.begin() + j);
        i = j;
    }

    int cur = 1;
    bool ok = true;
    for (int i = 0; i < 4 * n; ++i) {
        if (a[i][0] < cur) {
            ok = false;
            break;
        }
        cur = a[i][0];
    }

    cout << (ok ? "YES" : "NO") << endl;
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
