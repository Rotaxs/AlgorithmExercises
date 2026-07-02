#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int find(vector<int> &fa, int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa, fa[x]);
}

void unite(vector<int> &fa, int i, int j)
{
    int x = find(fa, i), y = find(fa, j);
    if (x == y) return;
    fa[x] = y;
}

void solve()
{
    int n, m;
    while (cin >> n && n != 0)
    {
        cin >> m;
        vector<int> fa(n + 1);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        int u, v;
        while (m--)
        {
            cin >> u >> v;
            unite(fa, u, v);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (fa[i] == i)
                cnt++;
        }
        cout << cnt - 1 << '\n';
    }
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