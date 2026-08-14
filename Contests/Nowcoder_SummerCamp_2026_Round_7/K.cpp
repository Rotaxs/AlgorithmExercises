#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

bool isUpper(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

void solve()
{
    int n; cin >> n; cin.ignore();
    vector<vector<string>> abbrs(n + 1);
    for (int i = 1; i <= n; ++i) {
        string line; 
        getline(cin, line);
        string upper = "";
        for (char ch : line) {
            if (isUpper(ch)) {
                upper += ch;
            }
        }
        abbrs[i].push_back(upper);
        string abbr = "";
        int cnt = 1;
        for (char ch : line) {
            if (ch == ' ') continue;
            if (isUpper(ch) && !abbr.empty()) {
                abbrs[i].push_back(abbr + upper.substr(cnt));
                ++cnt;
            }
            abbr += ch;
        }
        abbrs[i].push_back(abbr);
    }

    vector<string> ans(n + 1);
    vector<bool> locked(n + 1, false);
    vector<int> idx(n + 1, 0);

    bool ok = false;
    while (!ok) {
        ok = true;
        map<string, int> cnt;
        for (int i = 1; i <= n; ++i) {
            ans[i] = abbrs[i][idx[i]];
            cnt[ans[i]]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (locked[i]) continue;
            if (cnt[ans[i]] >= 2) {
                idx[i]++;
                ok = false;
            } else {
                locked[i] = true;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    // cin >> _;
    while (_--) solve();
    
    return 0;
}