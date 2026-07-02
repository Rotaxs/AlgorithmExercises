#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> gmap;
int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};

void print_mat(vector<vector<int>> mat)
{
    for (const auto &arr : mat)
    {
        for (const int &e : arr)
        {
            cout << e << ' ';
        }
        cout << '\n';
    }
}

void dfs(int r, int c, int src, int dst)
{
    // 1. 边界检查
    if (r < 0 || c < 0 || r >= N || c >= N)
        return;
    // 2. 如果当前点不是我们要染的颜色(src)，或者已经是目标颜色(dst)，直接返回
    if (gmap[r][c] != src)
        return;

    // 3. 染色当前点
    gmap[r][c] = dst;

    // 4. 递归四个方向
    for (int i = 0; i < 4; i++)
    {
        dfs(r + dr[i], c + dc[i], src, dst);
    }
}

int main()
{
    cin >> N;
    gmap.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> gmap[i][j];
        }
    }
    // 把边界的 0 染成 3
    for (int i = 0; i < N; i++)
    {
        dfs(0, i, 0, 3);
        dfs(N - 1, i, 0, 3);
        dfs(i, 0, 0, 3);
        dfs(i, N - 1, 0, 3);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (gmap[i][j] == 3)
                cout << 0 << ' ';
            if (gmap[i][j] == 1)
                cout << 1 << ' ';
            if (gmap[i][j] == 0)
                cout << 2 << ' ';
        }
        cout << '\n';
    }

    // print_mat(gmap);
    return 0;
}