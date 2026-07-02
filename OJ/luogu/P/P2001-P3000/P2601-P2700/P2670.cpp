#include <iostream>
#include <cstring>
using namespace std;

const int N = 100 + 10;

char arr[N][N];
short cnt[N][N] = {0};

void dump_hash(int i, int j)
{
    int count = 0;
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            if (arr[i + x][j + y] == '*')
                cnt[i][j]++;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == '?')
                dump_hash(i, j);
            else if (arr[i][j] == '*')
                cnt[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (cnt[i][j] == -1)
                cout << '*';
            else
                cout << cnt[i][j];
        }
        cout << endl;
    }
    return 0;
}
