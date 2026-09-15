#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    stack<int> st;
    unordered_map<int, bool> used;
    for (int i = 1; i <= n; ++i) {
        char op;
        int x;
        cin >> op >> x;
        if (op == '+') {
            while (used[x]) {
                int p = st.top();
                used[p] = false;
                st.pop();
                cout << '-';
            }
            st.push(x);
            used[x] = true;
            cout << '+';
        } else {
            if (op == 'T') {
                cout << '?';
            } else {
                while (used[x]) {
                    int p = st.top();
                    used[p] = false;
                    st.pop();
                    cout << '-';
                }
                cout << '?';
            }
        }
    }
    while (!st.empty()) {
        st.pop();
        cout << '-';
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
