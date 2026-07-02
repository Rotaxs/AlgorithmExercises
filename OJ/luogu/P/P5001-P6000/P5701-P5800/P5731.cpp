#include <iostream>
using namespace std;

const int N = 10;
int arr[N][N] = {0};
int n;

int main()
{
    cin >> n;
    int cur_r = 1, cur_c = 1, ne_r, ne_c;
    int dr[] = {0, -1, 0, 1}, dc[] = {-1, 0, 1, 0};
    int j = 0;
    for (int i = 1; i <= n * n; i++)
    {
        arr[cur_r][cur_c] = i;
        ne_r = cur_r + dr[j];
        ne_c = cur_c + dc[j];
        if (ne_r > n || ne_r <= 0 || ne_c > n || ne_c <= 0 || arr[ne_r][ne_c])
        {
            for (j = 0; j < 4; j++)
            {
                ne_r = cur_r + dr[j];
                ne_c = cur_c + dc[j];
                if (ne_r > n || ne_r <= 0 || ne_c > n || ne_c <= 0)
                    continue;
                if (arr[ne_r][ne_c])
                    continue;
                break;
            }
        }
        cur_c = ne_c;
        cur_r = ne_r;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%3d", arr[i][j]);
        putchar('\n');
    }
    return 0;
}