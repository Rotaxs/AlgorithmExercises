// https://www.luogu.com.cn/problem/P4924
#include <bits/stdc++.h>
using namespace std;

const int Z = 410;
vector<vector<int>> cmds;
string mat[Z];

void rotate(int x, int y, int l)
{
    // i 代表当前是第几层
    for (int i = 1; i <= l / 2; i++)
    {
        // 算出这个全的四个角
        int r1 = x + i - 1;
        int c1 = y + i - 1;
        int r2 = x + l - i;
        int c2 = y + l - i;

        // offset 是相对于当前圈起点的偏移量
        for (int offset = 0; offset < (l - 2 * (i - 1) - 1); offset++)
        {
            // 暂存上边
            int tmp = mat[r1][c1 + offset];
            // 上边 = 左边
            mat[r1][c1 + offset] = mat[r2 - offset][c1];
            // 左边 = 下边
            mat[r2 - offset][c1] = mat[r2][c2 - offset];
            // 下边 = 右边
            mat[r2][c2 - offset] = mat[r1 + offset][c2];
            // 右边 = 暂存的上边
            mat[r1 + offset][c2] = tmp;
        }
    }
}

void rotate(int x, int y, int l, int d)
{
    for (int i = 1; i <= d; i++)
        rotate(x, y, l);
}

void flip(int x, int y, int lx, int ly, int dir)
{
    // 左右翻转
    if (dir == -1)
    {
        for (int i = x; i <= x + lx - 1; i++)
            for (int j = y; j <= y + ly / 2 - 1; j++)
                swap(mat[i][j], mat[i][2 * y + ly - 1 - j]);
    }
    // 上下翻转
    else if (dir == 1)
    {
        for (int j = y; j <= y + ly - 1; j++)
            for (int i = x; i <= x + lx / 2 - 1; i++)
                swap(mat[i][j], mat[2 * x + lx - 1 - i][j]);
    }
}

void solve()
{
    int z; cin >> z;
    for (int i = 0; i < z; i++)
    {
        string row; cin >> row;
        mat[i] = row;
    }
    int t; cin >> t; cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> cmd(6);
        cin >> cmd[0] >> cmd[1] >> cmd[2] >> cmd[3] >> cmd[4] >> cmd[5];
        cmds.push_back(cmd);
    }
    int len_cmd = cmds.size();
    for (int i = len_cmd - 1; i >= 0; i--)
    {
        if (cmds[i][0] == 1)
        {
            int u, v, l, d, r;
            u = cmds[i][1]; 
            v = cmds[i][2];
            l = cmds[i][3]; 
            d = cmds[i][4]; 
            r = cmds[i][5];
            rotate(0, 0, z, r % 4);
            rotate(u - 1, v - 1, l, 4 - d / 90);
        }
        else
        {
            int u, d, l, r, o;
            u = cmds[i][1]; 
            d = cmds[i][2];
            l = cmds[i][3]; 
            r = cmds[i][4];
            o = cmds[i][5];
            // flip(u, l, d - u + 1, r - l + 1, o);
            flip(u - 1, l - 1, d - u + 1, r - l + 1, o);
        }
    }

    int n = 0, m = 0;
    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < z; j++)
        {
            if (mat[i][j] != '?')
            {
                n = max(n, i + 1);
                m = max(m, j + 1);
            }
        }
    }
    cout << n << " " << m << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j];
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();

    return 0;
}

