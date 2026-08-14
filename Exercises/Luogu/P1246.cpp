#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int ans;

int c(int m, int n)
{
    if (m == 0)
        return 1;
    int ret = 1;
    for (int i = n; i > n - m; i--)
        ret *= i;
    for (int i = m; i > 1; i--)
        ret /= i;
    return ret;
}

void solve()
{
    cin >> s;
    int len = s.size();
    for (int i = 1; i < len; i++)
    {
        if (s[i] <= s[i - 1])
        {
            cout << 0 << '\n';
            return;
        }
    }
    for (int i = 1; i < len; i++)
        ans += c(i, 26);
    char prev = 'a' - 1;
    for (int i = 0; i < len; i++)
    {
        for (char cur = prev + 1; cur < s[i]; cur++)
        {
            ans += c(len - 1 - i, 'z' - cur);
        }
        prev = s[i];
    }

    cout << ++ans << '\n';
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