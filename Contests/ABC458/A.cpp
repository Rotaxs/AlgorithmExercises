#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s;
    int n;
    cin >> s >> n;
    for (int i = n; i < s.size() - n; i++)
        cout << s[i];
    cout << '\n';
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