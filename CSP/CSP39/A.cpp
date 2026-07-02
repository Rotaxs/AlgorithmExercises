#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n, a; cin >> n >> a;
    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        double x, y; cin >> x >> y;
        if (x * x + y * y <= a * a) m++;
    }
    cout << (4 * (double)m / n) << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}