#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string f(s.length(), '0');
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != f[i])
        {
            if (i + k < n)
            {
                f[i] = f[i] == '1' ? '0' : '1';
                f[i + k] = f[i + k] == '1' ? '0' : '1';
            }
            else break;
        }
    }
    if (f == s) cout << "YES\n";
    else cout << "NO\n";
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