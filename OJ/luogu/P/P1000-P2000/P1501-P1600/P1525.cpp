#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 1e5 + 10;
const int N = 2e4 + 10;

int fa[N << 1];

struct crimer { int a, b, c; } e[M];

bool cmp(crimer a, crimer b)
{
    return a.c > b.c;
}

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
    for (int i = 1; i <= m; i++) cin >> e[i].a >> e[i].b >> e[i].c;
    for (int i = 1; i <= n * 2; i++) fa[i] = i;
    sort(e + 1, e + m + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int x = e[i].a, y = e[i].b;
        if (find(x) == find(y))
        {
            ans = e[i].c;
            break;
        }
        else
        {
            unite(x, y + n);
            unite(y, x + n);
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