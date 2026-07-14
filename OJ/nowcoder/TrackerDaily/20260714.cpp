#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

map<string, bool> mp;

void solve()
{
    int n, q; cin >> n >> q;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        if (mp[s])
        {
            ans++;
            mp[s] = false;;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int op; cin >> op;
        if (op == 1)
        {
            string s; cin >> s;
            if (mp[s])
            {
                ans++;
                mp[s] = false;
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