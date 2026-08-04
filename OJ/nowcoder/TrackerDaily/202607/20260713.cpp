#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void read(vector<int> &a, int i, int m)
{
    int res = 0;
    for (int j = 1; j <= m; j++)
    {
        char c; cin >> c;
        res = res * 2 + c - '0';
    }
    a[i] = res;
}

int dfs(int t, vector<int> &me, int k, int start, int cur, int step)
{
    if ((cur & t) == t)
    {
        return step;
    }

    int res = inf;
    for (int i = start; i <= k; i++)
    {
        res = min(res, dfs(t, me, k, i + 1, cur | me[i], step + 1));
    }

    return res;
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> pa(n + 1);
    for (int i = 1; i <= n; i++)
        read(pa, i, m);
    int k; cin >> k;
    vector<int> me(k + 1);
    for (int i = 1; i <= k; i++)
        read(me, i, m);
    for (int i = 1; i <= n; i++)
    {
        int ans = dfs(pa[i], me, k, 1, 0, 0);
        cout << (ans == inf ? -1 : ans) << endl;
    }   
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