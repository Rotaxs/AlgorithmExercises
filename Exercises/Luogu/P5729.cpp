#include <iostream>
using namespace std;

const int N = 25;
int cube[N][N][N];
int w, x, h, q;

int main()
{
    cin >> w >> x >> h;
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            for (int k = 1; k <= h; k++)
            {
                cube[i][j][k] = 1;
            }
        }
    }

    cin >> q;
    int x1, x2, y1, y2, z1, z2;
    for (int i = 0; i < q; i++)
    {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int a = x1; a <= x2; a++)
        {
            for (int b = y1; b <= y2; b++)
            {
                for (int c = z1; c <= z2; c++)
                {
                    cube[a][b][c] = 0;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            for (int k = 1; k <= h; k++)
            {
                if (cube[i][j][k] == 1)
                    ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}