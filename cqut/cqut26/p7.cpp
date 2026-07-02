#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(char a, char b)
{
    if (a == '?' || b == '?' || a == b) return true;
    return false;
}


void solve()
{
    string s;
    cin >> s;
    int ans = 0;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        int l = i, r = i;
        while (check(s[l], s[r]))
        {
            ans++;
            l--, r++;
            if (l < 0 || r >= len) break;
        }
    }
    for (int i = 0; i < len - 1; i++)
    {
        int l = i, r = i + 1;
        while (check(s[l], s[r]))
        {
            ans++;
            l--, r++;
            if (l < 0 || r >= len) break;
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