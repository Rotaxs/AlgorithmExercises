#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    // int sum = 0;

    // for (char c : s) {
    //     if (c == '0')
    //         ++sum;
    //     else
    //         --sum;
    // }

    // cout << n - abs(sum) << endl;

    stack<char> st;

    for (int c : s) {
        if (!st.empty() && st.top() != c) {
            st.pop();
        } else {
            st.push(c);
        }
    }

    cout << n - st.size() << endl;
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
