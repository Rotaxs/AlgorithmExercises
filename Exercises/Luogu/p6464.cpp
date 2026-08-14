#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 110;
const int inf  = 0x3f3f3f3f;

int f[N][N];

void floyd(int n)
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
}

ll calc(int x, int y, int n)
{
    ll ret = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            ret += min({f[i][j], f[i][x] + f[y][j], f[i][y] + f[x][j]});
    return ret;
}

void solve()
{
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = (i == j ? 0 : inf);
    while (m--)
    {
        int x, y, w; cin >> x >> y >> w;
        f[x][y] = f[y][x] = w;
    }
    floyd(n);
    ll ans = 0x3f3f3f3f3f3f3f3f;
    // calc(1, 4, n);
    for (int x = 1; x <= n; x++)
    {
        for (int y = x + 1; y <= n; y++)
        {
            ll tmp = calc(x, y, n);
            ans = min(ans, tmp);
        }
    }
    cout << ans << '\n';
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