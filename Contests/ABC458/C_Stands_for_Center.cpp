#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; cin >> s;
    ll ans = 0;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'C')
        {
            ans += min(i, len - 1 - i) + 1;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();
    
    return 0;
}