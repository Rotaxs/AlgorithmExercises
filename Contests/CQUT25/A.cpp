#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s, t;
    cin >> s >> t;
    string test = "";
    test += s[0];

    int len = s.length();
    for (int i = 0; i < len - 1; i++)
    {
        if (s[i] == '_')
        {
            test += s[i + 1];
        }
    }
    cout << (test == t ? "Yes" : "No") << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}