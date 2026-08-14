#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 2010;
int mat[N][N];
int memo[N][N];
int ans[N];

int get(int i, int j)
{
    if (i <= 0 || j <= 0) return 0;
    if (i > n || j > n) return 0;
    return mat[i][j];
}

bool check(int i, int j, int k)
{
    return k * k == get(i + k - 1, j + k - 1) + get(i - 1, j - 1) - get(i + k - 1, j - 1) - get(i - 1, j + k - 1);
}

int bisearch(int i, int j, int maxlen)
{
    int l = 0, r = maxlen + 1;
    while (l + 1 != r)
    {
        int m = l + ((r - l) >> 1);
        if (check(i, j, m)) l = m;
        else r = m;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    char c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            mat[i][j] = c - '0';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            memo[i][j] = bisearch(i, j, max(n - i + 1, n - j + 1));
            ans[memo[i][j]]++;
        }
    }
    
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << memo[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int i = n - 1; i >= 1; i--)
    {
        ans[i] += ans[i + 1];
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';

    return 0;
}