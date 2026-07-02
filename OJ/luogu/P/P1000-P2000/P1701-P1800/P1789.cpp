#include <iostream>
using namespace std;

const int N = 110;
bool light[N][N] = {false};

int main()
{
    int n, m, k;
    int x, y;
    int torch_x[] = {0, 0, -1, -2, -1, -1, 0, 0, 1, 2, 1, 1};
    int torch_y[] = {-2, -1, -1, 0, 0, 1, 2, 1, 1, 0, 0, -1};
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        light[x][y] = true;
        for (int j = 0; j < 12; j++)
        {
            int ne_x = x + torch_x[j];
            int ne_y = y + torch_y[j];
            if (ne_x < 0 || ne_x > n || ne_y < 0 || ne_y > n)
                continue;
            light[ne_x][ne_y] = true;
        }
    }
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        for (int dx = -2; dx <= 2; dx++)
        {
            for (int dy = -2; dy <= 2; dy++)
            {
                int ne_x = x + dx;
                int ne_y = y + dy;
                if (ne_x < 0 || ne_x > n || ne_y < 0 || ne_y > n)
                    continue;
                light[ne_x][ne_y] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // cout << light[i][j] << ' ';
            if (!light[i][j])
                ans++;
        }
        // cout << '\n';
    }
    cout << ans << '\n';
    return 0;
}