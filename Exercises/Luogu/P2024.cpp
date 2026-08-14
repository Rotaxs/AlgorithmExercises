#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100010;
int ans, n, k, t, x, y;
int fa[N << 2], rk[N << 2];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void merge(int x, int y)
{
    x = find(x); y = find(y);
    if (rk[x] > rk[y]) swap(x, y);
    if (rk[x] == rk[y]) rk[y]++;
    fa[x] = y;
}

void solve()
{
    cin >> n >> t;
    for (int i = 1; i <= 3 * n + 1; i++) fa[i] = i;
    for (int i = 1; i <= t; i++)
    {
        cin >> k >> x >> y;
        if (x < 1 || x > n || y < 1 || y > n)
        {
            ans++;
            continue;
        }
        if (k == 1)
        {
            if (find(x) == find(y + n) || find(y + 2 * n) == find(x))
            {
                ans++;
            }
            else
            {
                merge(x, y);
                merge(x + n, y + n);
                merge(x + 2 * n, y + 2 * n);
            }
        }
        if (k == 2)
        {
            if (find(x) == find(y) || find(x) == find(y + 2 * n))
            {
                ans++;
            }
            else
            {
                merge(x, y + n);
                merge(x + n, y + 2 * n);
                merge(x + 2 * n, y);
            }
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
