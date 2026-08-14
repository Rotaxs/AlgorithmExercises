#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> l(n + 1, 1);
    vector<int> r(n + 1, 1e9);
    for (int i = 1, p, x, y; i <= q; i++)
    {
        cin >> p >> x >> y;
        l[p] = max(l[p], x);
        r[p] = min(r[p], y);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (l[i] > r[i])
        {
            cout << -1 << '\n';
            return;
        }
        if (a[i] < l[i])
            ans += l[i] - a[i];
        else if (a[i] > r[i])
            ans += a[i] - r[i];
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