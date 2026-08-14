#include <iostream>
using namespace std;

const int R = 110, C = 110;
int r, c, k;
char mat[R][C];

bool get_dot_count(int cnt, int cur_r, int cur_c, int dr, int dc)
{
    // 这个判断只能判断第一次进入函数的状态
    // 因为只要 (ne_r, ne_c) 过不去，就无法再进入下一次递归
    if (mat[cur_r][cur_c] == '#')
        return false;
    // cnt 初始化为 1
    if (cnt >= k)
        return true;
    int ne_r = cur_r + dr;
    int ne_c = cur_c + dc;
    if (ne_r <= 0 || ne_r > r || ne_c <= 0 || ne_c > c)
        return false;
    if (mat[ne_r][ne_c] == '#')
        return false;
    return get_dot_count(++cnt, ne_r, ne_c, dr, dc);
}

int main()
{
    cin >> r >> c >> k;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> mat[i][j];
    int ans = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            // 只往右方和下方搜索
            if (get_dot_count(1, i, j, 0, 1))
                ans++;
            if (get_dot_count(1, i, j, 1, 0))
                ans++;
        }
    }
    // k = 1 的情况要特判
    // 这时向下和向右会重复计算
    if (k == 1)
        ans /= 2;
    cout << ans << '\n';
    return 0;
}