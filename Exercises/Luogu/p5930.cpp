#include <iostream>
using namespace std;

const int N = 110;
int n, m;
int mat[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
        }
    }
    return 0;
}