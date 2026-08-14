#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 3e5 + 10;

struct Point
{
    int x, y;
    bool operator<(const Point &other) const
    {
        if (x < other.x) return true;
        if (x == other.x)
        {
            if (y < other.y) return true;
        }
        return false;
    }
} p[N];

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    sort(p + 1, p + n + 1);
    int ans = 0;
    int miny = 1e9;
    for (int i = 1; i <= n; i++)
    {   
        if (p[i].y < miny)
        {
            ans++;
            miny = p[i].y;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    
    return 0;
}