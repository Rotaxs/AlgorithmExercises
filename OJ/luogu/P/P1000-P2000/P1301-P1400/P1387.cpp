#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110, M = 110;
int n, m;
int mat[N][M];

int get(int r, int c) { return (r < 0 || c < 0) ? 0 : mat[r][c]; }

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mat[i][j] += mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1];

    int ans = 0;
    for (int a = 1; a <= n; a++)
    {
        for (int b = 1; b <= m; b++)
        {
            for (int c = ans + 1; a + c - 1 <= n && b + c - 1 <= m; c++)
            {
                int sum = mat[a + c - 1][b + c - 1] - mat[a + c - 1][b - 1] - mat[a - 1][b + c - 1] + mat[a - 1][b - 1];
                if (sum == c * c)
                    ans = c;
                else
                    break;
            }
        }
    }
    cout << ans << endl;

    // (a, b) 表示左上角顶点，c 表示正方形边长
    // int c, sq;
    // bool found = false;
    // for (c = min(n, m); c >= 0; c--)
    // {
    //     sq = c * c;
    //     for (int a = 1; a + c - 1 <= n; a++)
    //     {
    //         for (int b = 1; b + c - 1 <= m; b++)
    //         {
    //             int sum = mat[a + c - 1][b + c - 1] - mat[a + c - 1][b - 1] - mat[a - 1][b + c - 1] + mat[a - 1][b - 1];
    //             if (sum == sq)
    //             {
    //                 found = true;
    //                 break;
    //             }
    //         }
    //         if (found)
    //             break;
    //     }
    //     if (found)
    //         break;
    // }
    // cout << c << '\n';

    return 0;
}