#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n, m;
vector<vector<int>> mat;

void print_mat(vector<vector<int>> mat, int r, int c)
{
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
        {
            cout << mat[x][y] << " ";
        }
        cout << "\n";
    }
}

pair<int, int> dir_rotate(pair<int, int> dir, int z)
{
    int tmp;
    // 利用虚数乘法表示旋转
    // 顺时针，乘 -i
    if (z == 1)
    {
        tmp = dir.first;
        dir.first = -dir.second;
        dir.second = tmp;
    }
    // 逆时针，乘 i
    else if (z == 0)
    {
        tmp = dir.first;
        dir.first = dir.second;
        dir.second = -tmp;
    }
    return dir;
}

void rotate(vector<vector<int>> &mat, int x, int y, int r, int z)
{
    pair<int, int> dir, new_dir;
    int tmp;
    for (int c = 1; c <= r; c++)
    {
        // 边长为 2c + 1，但是只需要旋转 2c 个点
        // 这 2c 个点是左边的不包括左下角的点
        // 从左上角往下走 2c 个点
        // 每次循环处理一组四个点
        for (int d = -c; d <= c - 1; d++)
        {
            dir.first = d;
            dir.second = -c; // 由于在左边界，因此列向量不变
            tmp = mat[x + dir.first][y + dir.second];
            for (int i = 0; i < 3; i++)
            {
                // 将左边界点点存下来后
                // 若要实现逆时针，需要顺时针的点
                // 若要实现顺时针，需要逆时针的点
                new_dir = dir_rotate(dir, !z);
                mat[x + dir.first][y + dir.second] = mat[x + new_dir.first][y + new_dir.second];
                dir = new_dir;
            }
            mat[x + dir.first][y + dir.second] = tmp;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // 初始化矩阵
    mat.resize(n);
    for (auto &e : mat)
        e.resize(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cnt++;
            mat[i][j] = cnt;
        }
    }

    // print_mat(mat, n, n);

    // 旋转矩阵
    int x, y, r, z;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> r >> z;
        x--;
        y--;
        rotate(mat, x, y, r, z);
    }

    print_mat(mat, n, n);

    return 0;
}