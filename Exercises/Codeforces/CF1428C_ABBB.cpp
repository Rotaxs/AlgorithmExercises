#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    string s;
    cin >> s;
    // stack<char> st;

    // for (char c : s) {
    //     if (!st.empty() && c == 'B') {
    //         st.pop();
    //     } else {
    //         st.push(c);
    //     }
    // }

    // cout << st.size() << endl;

    int sum = 0;
    for (char c : s) {
        if (c == 'A') {
            ++sum;
        } else {
            if (sum > 0)
                --sum;
            else
                ++sum;
        }
    }

    cout << sum << endl;
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
