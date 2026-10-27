#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    string s;
    cin >> s;
    stack<char> st;

    for (char c : s) {
        if (c == 'C' && st.size() >= 2) {
            char b = st.top();
            if (b != 'B') {
                st.push(c);
                continue;
            }
            st.pop();
            char a = st.top();
            if (a != 'A') {
                st.push(b);
                st.push(c);
                continue;
            }
            st.pop();
        } else {
            st.push(c);
        }
    }

    vector<char> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    int len = ans.size();
    for (int i = len - 1; i >= 0; --i) {
        cout << ans[i];
    }
    cout << endl;
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
