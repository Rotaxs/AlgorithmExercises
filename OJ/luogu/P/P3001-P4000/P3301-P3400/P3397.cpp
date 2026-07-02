#include <iostream>
using namespace std;

const int N = 1010;
int n, m;
int mat[N][N] = {0};

int main()
{
    cin >> n >> m;
    int x1, y1, x2, y2;
    while (m--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        mat[x1][y1]++;
        mat[x1][y2 + 1]--;
        mat[x2 + 1][y1]--;
        mat[x2 + 1][y2 + 1]++;
    }
    // 这里只要到 n 就可以了，虽然 n + 1 可能被影响
    // 但是其对原矩阵的有效部分没有影响
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            mat[i][j] += mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1];
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}