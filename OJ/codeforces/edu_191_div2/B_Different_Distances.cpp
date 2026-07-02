#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    if (n == 2)
    {
        cout << "1 2 2 1 1 2 1 2\n";
        return;
    }
    for (int i = 1; i <= n; i++)
        cout << i << ' ' << i << ' ';
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j <= n - 2; j++)
            cout << j << ' ';
        cout << n << ' ' << n - 1 << ' ';
    }
    cout << '\n';
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