#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int N = 55, M = 55;
char mat[N][M];
int ans = INT_MAX;
int n, m;

int get_cost(int W, int B, int R)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        char target;
        if (i < W)
            target = 'W'; // 前 W 行染白
        else if (i < W + B)
            target = 'B'; // 中间 B 行染蓝
        else
            target = 'R'; // 剩下 R 行染红

        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] != target)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    cin >> n >> m;
    char color;
    int r = 0, c = 0;
    for (int i = 0; i < n * m; i++)
    {
        if (cin >> color)
        {
            r = i / m;
            c = i % m;
            mat[r][c] = color;
        }
    }
    int W, B, R;
    for (W = 1; W <= n - 2; W++)
    {
        for (B = 1; B <= n - 2; B++)
        {
            if (W + B < n)
                R = n - W - B;
            else
                break;
            ans = min(ans, get_cost(W, B, R));
        }
    }
    cout << ans << '\n';
    return 0;
}