#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n; cin >> n;
    double e = 0.01,  p = sqrt(e) / 2;
    cout << 2 * n << endl;
    cout << fixed << setprecision(9);
    double x = -p, y = -p;
    for (int i = 0; i < n; i++)
    {
        cout << x << ' ' << y << ' '  << 0 << endl;
        cout << x << ' ' << y << ' '  << 1 << endl;
        y += 0.011;
        if (y - p > 1e-7) { x += 0.011; y = -p; }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}