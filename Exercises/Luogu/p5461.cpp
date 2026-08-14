#include <iostream>
using namespace std;

const int N = (1 << 10) + 1;
int mat[N][N] = {0};

void solu(int start_r, int start_c, int len)
{
    if (len == 1)
        return;
    int half_len = len / 2;
    // 处理 [start_r, start_c] 开始的边长为 len 的正方形
    // 将左上角全部赦免，填充为 1
    for (int r = start_r; r < start_r + half_len; r++)
    {
        for (int c = start_c; c < start_c + half_len; c++)
        {
            mat[r][c] = 1;
        }
    }
    solu(start_r + half_len, start_c, half_len);            // 下方正方形
    solu(start_r, start_c + half_len, half_len);            // 右方正方形
    solu(start_r + half_len, start_c + half_len, half_len); // 右下方正方形
}

int main()
{
    int n;
    cin >> n;
    int len = 1 << n;
    solu(1, 1, len);
    for (int r = 1; r <= len; r++)
    {
        for (int c = 1; c <= len; c++)
            cout << !mat[r][c] << ' ';
        cout << '\n';
    }
    return 0;
}