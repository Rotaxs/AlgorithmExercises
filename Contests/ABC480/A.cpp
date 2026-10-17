#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    string l1, l2;
    cin >> l1 >> l2;
    int posA, posD;
    string s = l1 + l2;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') {
            posA = i;
        }
        if (s[i] == 'D') {
            posD = i;
        }
    }

    if ((posA == 1 && posD == 2) || (posD == 1 && posA == 2)) {
        cout << "No" << endl;
        return;
    }

    if (abs(posA - posD) == 1 || abs(posA - posD) == 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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
