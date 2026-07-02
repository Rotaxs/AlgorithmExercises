#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef long long ll;
typedef unsigned long long ull;

ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a < b ? a : b; }
int n, m, k = 0;

void act1(vector<vector<int>> &ans, int x, int y)
{
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (j % 4 == 1)
                ans[i][j] = ++k;
            else
                ans[i][j] = k;
        }
    }
}

void act2(vector<vector<int>> &ans, int x, int y)
{
    ans[x][y] = ++k;
    ans[x][y + 1] = k;
    ans[x + 1][y] = k;
    ans[x + 2][y] = k;
    k++;
    ans[x + 3][y] = ans[x + 4][y] = ans[x + 5][y] = ans[x + 5][y + 1] = k;
    k++;
    for (int i = x + 1; i <= x + 4; i++)
        ans[i][y + 1] = k;
}

void act3(vector<vector<int>> &ans, int y, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i % 4 == 1)
            ans[i][y] = ++k;
        else
            ans[i][y] = k;
    }
}

void solve()
{
    cin >> n >> m;
    k = 0;
    if (n % 4 && m % 4 && (n % 2 || m % 2))
    {
        cout << "NO" << endl;
        return;
    }
    if (max(n, m) == 2)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    bool flag = false;
    if (n % 4 == 0 || m % 4 == 0)
    {
        if (n % 4)
        {
            swap(n, m);
            vector<vector<int>> ans(n + 5, vector<int>(m + 5));
            act1(ans, n, m / 4 * 4);
            for (int i = m / 4 * 4 + 1; i <= m; i++)
                act3(ans, i, n);
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << ans[j][i] << ' ';
                }
                cout << endl;
            }
            return;
        }
        else
        {
            vector<vector<int>> ans(n + 5, vector<int>(m + 5));
            act1(ans, n, m / 4 * 4);
            for (int i = m / 4 * 4 + 1; i <= m; i++)
                act3(ans, i, n);
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    cout << ans[i][j] << ' ';
                }
                cout << endl;
            }
            return;
        }
    }
    else
    {
        if (n < m)
        {
            swap(n, m);
            vector<vector<int>> ans(n + 5, vector<int>(m + 5));
            for (int i = 1; i <= m; i += 2)
                act2(ans, n - 5, i);
            act1(ans, n - 6, m / 4 * 4);
            for (int i = m / 4 * 4 + 1; i <= m; i++)
                act3(ans, i, n - 6);
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << ans[j][i] << ' ';
                }
                cout << endl;
            }
            return;
        }
        else
        {
            vector<vector<int>> ans(n + 5, vector<int>(m + 5));
            for (int i = 1; i <= m; i += 2)
                act2(ans, n - 5, i);
            act1(ans, n - 6, m / 4 * 4);
            for (int i = m / 4 * 4 + 1; i <= m; i++)
                act3(ans, i, n - 6);
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    cout << ans[i][j] << ' ';
                }
                cout << endl;
            }
            return;
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}