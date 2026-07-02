#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    string s; cin >> s;
    int len = s.length() - 1;
    int ans = 0;
    for (int i = 0; i <= len >> 1; ++i)
    {
        if (s[i] == s[len - i]) continue;
        ans += min(abs(s[i] - s[len - i]), 26 - abs(s[i] - s[len - i]));
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    
    return 0;
}