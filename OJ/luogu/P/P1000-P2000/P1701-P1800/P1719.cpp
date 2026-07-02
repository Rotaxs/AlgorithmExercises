#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> prefix;
vector<vector<int>> mat;

void resize_vec(vector<vector<int>> &vec, int x, int y, int n)
{
    vec.resize(x);
    for (auto &e : vec)
        e.resize(y, n);
}

void init_pre(vector<vector<int>> &prefix, vector<vector<int>> &mat, int x, int y)
{
    resize_vec(prefix, x + 1, y + 1, 0);
    for (int r = 1; r <= x; r++)
    {
        for (int c = 1; c <= y; c++)
        {
            prefix[r][c] = prefix[r - 1][c] + prefix[r][c - 1] + mat[r - 1][c - 1] - prefix[r - 1][c - 1];
        }
    }
}

void read(vector<vector<int>> &mat, int x, int y)
{
    resize_vec(mat, x, y, 0);
    for (int r = 0; r < x; r++)
    {
        for (int c = 0; c < y; c++)
        {
            cin >> mat[r][c];
        }
    }
}

void print_vec(vector<vector<int>> &vec, int x, int y)
{
    for (int r = 0; r < x; r++)
    {
        for (int c = 0; c < y; c++)
        {
            cout << vec[r][c] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    read(mat, n, n);
    init_pre(prefix, mat, n, n);
    // print_vec(prefix, n + 1, n + 1);

    int x1, x2, y1, y2, sum, max;
    max = prefix[1][1];
    for (x1 = 1; x1 <= n; x1++)
    {
        for (y1 = 1; y1 <= n; y1++)
        {
            for (x2 = x1; x2 <= n; x2++)
            {
                for (y2 = y1; y2 <= n; y2++)
                {
                    sum = prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
                    if (sum > max)
                        max = sum;
                }
            }
        }
    }
    cout << max << "\n";
    return 0;
}
