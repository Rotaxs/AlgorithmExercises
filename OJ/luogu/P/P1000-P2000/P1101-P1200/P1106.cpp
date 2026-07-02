#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int k;

void solve()
{
    cin >> s;
    cin >> k;
    while (k)
    {
        int i = 0;
        for (; s[i] <= s[i + 1]; i++)
            ;  // 找峰值
        s.erase(i, 1); // 删
        k--;
    }
    while (s[0] == '0' && s.size() > 1)
        s.erase(0, 1); // 前导零
    cout << s;
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