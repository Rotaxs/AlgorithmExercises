#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    int cur = n;
    bool imp = false;
    while (1)
    {
        cur -= a[cur];
        if (cur >= 0)
        {
            ans++;
            if (cur == 0) break;
        }
        if (cur < 0)
        {
            imp = true;
            break;
        }
    }
    if (imp) cout << -1 << '\n';
    else cout << ans << '\n';
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