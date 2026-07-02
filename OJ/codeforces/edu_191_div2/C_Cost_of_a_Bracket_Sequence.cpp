#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    int pre = 0;
    int minn = 0;
    int cut = 0;
    int cnt_close = 0;

    for (int i = 0; i < n; i++) 
    {
        if (s[i] == ')')
        {
            cnt_close++;
            pre--;
        } 
        else 
        {
            pre++;
        }

        if (pre < minn) 
        {
            minn = pre;
            cut = i + 1;
        }
    }

    int pairs = cnt_close + minn;
    int need_remove = min(k, pairs);
    string ans(n, '0');

    for (int i = 0; i < cut && need_remove > 0; i++) 
    {
        if (s[i] == '(') 
        {
            ans[i] = '1';
            need_remove--;
        }
    }
    for (int i = n - 1; i >= cut && need_remove > 0; i--) 
    {
        if (s[i] == ')') 
        {
            ans[i] = '1';
            need_remove--;
        }
    }

    cout << ans << '\n';
}   

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while (t--) solve();
    
    return 0;
}
