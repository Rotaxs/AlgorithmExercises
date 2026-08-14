/**
 * 给定一个 x * y 的二维数组 mat，求其前缀和数组 prefix
 * prefix[i-1][j-1] 表示 mat[0][0] 与 mat[i][j] 所围成的矩形中的所有元素的和
 */

/*
测试用例：
0 -2 -7 0
9 2 -6 2
-4 1 -4  1
-1 8  0 -2
*/

#include <iostream>
#include <vector>
using namespace std;

int x, y;
vector<vector<int>> prefix;
vector<vector<int>> mat;

void resize_vec(vector<vector<int>> &vec, int x, int y, int n)
{
    vec.resize(x);
    for (auto &e : vec)
        e.resize(y, n);
}

void init_pre(vector<vector<int>> &prefix, vector<vector<int>> &mat, int x, int y)
{
    resize_vec(prefix, x + 1, y + 1, 0);
    for (int r = 1; r <= x; r++)
    {
        for (int c = 1; c <= y; c++)
        {
            // 左 + 上 - 左上 + 自己
            prefix[r][c] = prefix[r - 1][c] + prefix[r][c - 1] + mat[r - 1][c - 1] - prefix[r - 1][c - 1];
        }
    }
}

void read(vector<vector<int>> &mat, int x, int y)
{
    resize_vec(mat, x, y, 0);
    for (int r = 0; r < x; r++)
    {
        for (int c = 0; c < y; c++)
        {
            cin >> mat[r][c];
        }
    }
}

void print_vec(vector<vector<int>> &vec, int x, int y)
{
    for (int r = 0; r < x; r++)
    {
        for (int c = 0; c < y; c++)
        {
            cout << vec[r][c] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    x = 4, y = 4;

    read(mat, x, y);
    init_pre(prefix, mat, x, y);
    print_vec(prefix, x + 1, y + 1);

    return 0;
}
