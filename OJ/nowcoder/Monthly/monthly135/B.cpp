#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int x; cin >> x;
    int a = 9, b = 0;
    int t = (x - a) % 100 / 10;
    if (t == 9)
    {
        b = x - a;
        cout << a << ' ' << b << '\n';
        return;
    }
    // cout << t << '\n';
    a = a + (10 + t - 9) * 10;
    b = x - a;
    cout << a << ' ' << b << '\n';
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