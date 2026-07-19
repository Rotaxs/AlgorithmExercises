#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

bool cmp(const string &a, const string &b)
{
    if (a.size() != b.size()) return a.size() > b.size();
    return a > b;
}

void solve()
{
    string x; cin >> x;
    string tmp = "";
    vector<string> ans;
    for (const char &c : x)
    {
        tmp += c;
        if (((c - '0') & 1) == 0) 
        {
            ans.push_back(tmp);
            tmp.clear();
        }
    }
    if (!tmp.empty()) ans.push_back(tmp);
    sort(ans.begin(), ans.end(), cmp);
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << endl;
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