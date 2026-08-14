#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f[1000];
int ans = 0;

// cnt 表示当前有多少个交点
void dfs(int n, int cnt)
{
    if (n == 0)
    {
        if (!f[cnt]) ans++;
        f[cnt] = true; 
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(n - i, i * (n - i) + cnt);
    }
}

void solve()
{
    int n;
    cin >> n;
    dfs(n, 0);
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    
    return 0;
}