#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    int a, b, c, d; cin >> a >> b >> c;
    vector<pair<int, int>> scores(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y; cin >> x >> y;
        scores[i].first = x;
        scores[i].second = y;
    }
    cin >> d;
    for (int i = 1; i <= n; i++)
    {
        bool f1 = false, f2 = false;
        int x = scores[i].first, y = scores[i].second;
        if (x + y < c) f1 = true;
        if (min(x + d, a) + y >= c) f2 = true;
        if (f1 && f2) ans++;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}