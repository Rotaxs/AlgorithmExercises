#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;

string s;
int n;
vector<int> kmp;

void Kmp()
{
    kmp.resize(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++)
    {
        while (j && s[j] != s[i])
            j = kmp[j - 1];
        if (s[j] == s[i])
            j++;
        kmp[i] = j;
    }
}

void solve()
{
    string t; cin >> s;
    Kmp();
    cin >> n;
    int ans = 0;
    while (n--)
    {
        cin >> t;
        int j = 0, res = 0;
        for (const auto &c : t)
        {
            while (j && s[j] != c)
                j = kmp[j - 1];
            if (s[j] == c)
            {
                j++;
                res = max(res, j);
                if (j == s.size())
                    j = kmp[j - 1];
            }
        }
        ans += res;
    }
    cout << ans << endl;
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
