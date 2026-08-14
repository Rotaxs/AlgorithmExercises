#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<vector<bool>> vis;
vector<int> path;
int ans = 0;
// col[i] 表示在第 i 列是否有皇后
// dg[i] 表示截距为 i 的主对角线是否有皇后
// udg[i + 20] 表示截距为 i 的副对角线是否有皇后
bool col[20], dg[40], udg[40];

// 判断第 r 行能否放置皇后
bool check(int r, int c)
{
    // i 遍历行，path[i] 表示第 i 行皇后所在的列
    for (int i = 1; i < r; i++)
    {
        // 不在同一行但在同一列
        if (path[i] == c)
            return false;
        // 在同一对角线
        if (r - i == abs(path[i] - c))
            return false;
    }
    return true;
}

void print(vector<int> path)
{
    for (int i = 1; i <= n; i++)
        cout << path[i] << ' ';
    cout << '\n';
}

void dfs(int step)
{
    if (step > n)
    {
        if (ans < 3)
            print(path);
        ans++;
        return;
    }

    // i 遍历 step 行的每一列
    for (int i = 1; i <= n; i++)
    {
        // if (check(step, i))
        // {
        //     path[step] = i;
        //     dfs(step + 1);
        //     path[step] = 0;
        // }
        if (!col[i] && !dg[step + i] && !udg[i - step + 20])
        {
            col[i] = dg[step + i] = udg[i - step + 20] = true;
            path[step] = i;

            dfs(step + 1);

            col[i] = dg[step + i] = udg[i - step + 20] = false;
        }
    }
}

int main()
{
    cin >> n;
    path.resize(n + 1);
    dfs(1);
    cout << ans << '\n';
    return 0;
}
