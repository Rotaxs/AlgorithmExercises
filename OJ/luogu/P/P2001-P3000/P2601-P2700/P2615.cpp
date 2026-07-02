#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> mat;

void generate_magic_square(vector<vector<int>> &mat)
{
    int row = 1, column = (n + 1) / 2;
    int n_row, n_column;
    mat[row][column] = 1;
    for (int i = 2; i <= n * n; i++)
    {
        if (row == 1 && column != n)
        {
            n_row = n;
            n_column = column + 1;
        }
        else if (row != 1 && column == n)
        {
            n_column = 1;
            n_row = row - 1;
        }
        else if (row == 1 && column == n)
        {
            n_row = row + 1;
            n_column = column;
        }
        else
        {
            if (!mat[row - 1][column + 1])
            {
                n_row = row - 1;
                n_column = column + 1;
            }
            else
            {
                n_row = row + 1;
                n_column = column;
            }
        }
        mat[n_row][n_column] = i;
        row = n_row;
        column = n_column;
    }
}

void print_mat(vector<vector<int>> mat)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    cin >> n;
    mat.assign(n + 1, vector<int>(n + 1, 0));
    generate_magic_square(mat);
    print_mat(mat);
    return 0;
}