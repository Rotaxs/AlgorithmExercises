#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

map<string, int> mp;

void solve()
{
    int n, q; cin >> n >> q;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        mp[s]++;
        if (mp[s] >= 2)
        {
            ans++;
            mp[s] = 1;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int op; cin >> op;
        if (op == 1)
        {
            string s; cin >> s;
            mp[s]++;
            if (mp[s] >= 2)
            {
                ans++;
                mp[s] = 1;
            }
        }
        else if (op == 2)
        {
            cout << ans << endl;
            ans = 0;
        }
    }
    // cout << ans << endl;
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