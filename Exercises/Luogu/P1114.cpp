#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve1()
{
    int n; cin >> n;
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> sum[i];
    for (int i = 2; i <= n; i++) sum[i] += sum[i - 1];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (j - i + 1 == 2 * (sum[j] - sum[i - 1]))
                ans = max(ans, j - i + 1);
    cout << ans << '\n';
}

void solve2()
{
    int n; cin >> n;
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> sum[i];
    for (int i = 2; i <= n; i++) sum[i] += sum[i - 1];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + ans - 1; j <= n; j++)
            if (j - i + 1 == 2 * (sum[j] - sum[i - 1]))
                ans = max(ans, j - i + 1);
    cout << ans << '\n';
}

void solve3()
{
    int n; cin >> n;
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        sum[i] = (a == 0 ? -1 : 1);
    }
    for (int i = 2; i <= n; i++) sum[i] += sum[i - 1];
    unordered_map<int, int> first;
    unordered_map<int, bool> vis;
    vis[0] = true;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[sum[i]])
        {
            first[sum[i]] = i;
            vis[sum[i]] = true;
        }
        else
        {
            ans = max(ans, i - first[sum[i]]);
        }
    }
    cout << ans << '\n';
}

void solve()
{
    int n; cin >> n;
    int ans = 0, sum = 0;
    vector<int> first(2 * n + 1, 0);
    vector<bool> vis(2 * n + 1, false);
    vis[n] = true;
    for (int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        sum += (a == 0 ? -1 : 1);
        int tmp = sum + n;
        if (!vis[tmp])
        {
            first[tmp] = i;
            vis[tmp] = true;
        }
        else 
        {
            ans = max(ans, i - first[tmp]);
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