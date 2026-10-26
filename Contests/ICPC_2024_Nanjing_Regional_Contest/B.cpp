#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    string s;
    cin >> s;
    int sum = 0;
    int two = 0;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (c == '0') {
            if (i % 2 == 0)
                ++sum;
            else
                --sum;
        } else if (c == '1') {
            if (i % 2 == 0)
                --sum;
            else
                ++sum;
        } else {
            ++two;
        }
    }

    cout << max(abs(sum) - two, len % 2) << endl;
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
