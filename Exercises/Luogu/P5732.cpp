#include <iostream>
using namespace std;

const int N = 21;
int mat[N][N] = {0};
int n;

int main()
{
    cin >> n;
    mat[0][0] = 1;
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= r; c++)
        {
            mat[r][c] = mat[r - 1][c] + mat[r - 1][c - 1];
        }
    }

    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= r; c++)
            cout << mat[r][c] << ' ';
        cout << '\n';
    }
    return 0;
}