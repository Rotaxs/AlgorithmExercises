#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    if (s.size() != t.size()) {
        cout << "NO" << endl;
        return;
    }

    vector<int> cnt_sb, cnt_sc, cnt_tb, cnt_tc;

    int cur_sb = 0, cur_sc = 0, cur_tb = 0, cur_tc = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'a') {
            cnt_sb.push_back(cur_sb);
        } else if (s[i] == 'b') {
            ++cur_sb;
            cnt_sc.push_back(cur_sc);
        } else {
            ++cur_sc;
        }

        if (t[i] == 'a') {
            cnt_tb.push_back(cur_tb);
        } else if (t[i] == 'b') {
            ++cur_tb;
            cnt_tc.push_back(cur_tc);
        } else {
            ++cur_tc;
        }
    }

    if (cnt_sb.size() != cnt_tb.size() || cnt_sc.size() != cnt_tc.size()) {
        cout << "NO" << endl;
        return;
    }

    for (int i = (int)cnt_sb.size() - 1; i >= 0; --i) {
        if (cnt_sb[i] < cnt_tb[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = (int)cnt_sc.size() - 1; i >= 0; --i) {
        if (cnt_sc[i] < cnt_tc[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    int cur1 = 0, cur2 = 0;
    vector<int> cnt1, cnt2;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'c') {
            ++cur1;
        } else if (s[i] == 'a') {
            cnt1.push_back(cur1);
        }

        if (t[i] == 'c') {
            ++cur2;
        } else if (t[i] == 'a') {
            cnt2.push_back(cur2);
        }
    }

    for (int i = (int)cnt1.size() - 1; i >= 0; --i) {
        if (cnt1[i] != cnt2[i]) {
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
