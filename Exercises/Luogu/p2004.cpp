#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010, M = 1010;
int n, m, c;
int mat[N][M];

int get(int r, int c) { return (r < 0 || c < 0) ? 0 : mat[r][c]; }

int main()
{
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mat[i][j] += mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1];
    int ar = 0, ac = 0;
    long long ans = -2e18;
    // (a, b) 表示左上角顶点
    for (int a = 1; a + c - 1 <= n; a++)
    {
        for (int b = 1; b + c - 1 <= m; b++)
        {
            long long sum = mat[a + c - 1][b + c - 1] - mat[a + c - 1][b - 1] - mat[a - 1][b + c - 1] + mat[a - 1][b - 1];
            if (sum > ans)
            {
                ans = sum;
                ar = a;
                ac = b;
            }
        }
    }
    cout << ar << ' ' << ac;
    return 0;
}