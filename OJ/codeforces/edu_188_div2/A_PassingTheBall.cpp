#include <bits/stdc++.h>
using namespace std;

const int N = 55;

void solve()
{
    int n; string s;
    cin >> n >> s;
    bool memo[N] = {0};
    memo[1] = true;
    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[p - 1] == 'R')
        {
            p++;
            if (!memo[p])
                memo[p] = true;
        }
        else
        {
            p--;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (memo[i])
            ans++;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}