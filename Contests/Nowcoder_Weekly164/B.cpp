#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

string a[3];

bool win() {
    for (int i = 0; i < 3; ++i) {
        if (a[i][0] == '1' && a[i][1] == '1' && a[i][2] == '1') return true;
        if (a[0][i] == '1' && a[1][i] == '1' && a[2][i] == '1') return true;
    }
    return (a[0][0] == '1' && a[1][1] == '1' && a[2][2] == '1') ||
           (a[0][2] == '1' && a[1][1] == '1' && a[2][0] == '1');
}

void solve() {

    for (int i = 0; i < 3; ++i)
        cin >> a[i];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (a[i][j] != '*') continue;
            a[i][j] = '1';
            if (win()) {
                cout << "Yes\n" << i + 1 << ' ' << j + 1 << '\n';
                return;
            }
            a[i][j] = '*';
        }
    }

    cout << "No\n";
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
