#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1010;

int fa[N << 1];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y)
{
    int rx = find(x), ry = find(y);
    if (rx == ry) return;
    fa[ry] = rx;
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n * 2; i++) fa[i] = i;
    while (m--)
    {
        char opt;
        int p, q;
        cin >> opt >> p >> q;
        if (opt == 'F')
        {
            unite(p, q);
        }
        else if (opt == 'E')
        {
            unite(q, p + n);
            unite(p, q + n);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] == i) ans++;
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

