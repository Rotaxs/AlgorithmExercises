#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6;

int n, m;
int arr[N][3];

int fa[N];
int ranks[N];

void init()
{
    for (int i = 0; i < n; i++)
    {
        fa[i] = i;
        ranks[i] = 1;
    }
}

int find(int x)
{
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

void unite(int i, int j)
{
    int x = find(i), y = find(j);
    if (x == y)
        return;
    if (ranks[x] < ranks[y])
        swap(x, y);
    fa[y] = x;
    if (ranks[x] == ranks[y])
        ranks[x]++;
}

int main()
{
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
    int X, Y, Z;
    for (int i = 0; i < m; i++)
    {
        Z = arr[i][0];
        X = arr[i][1];
        Y = arr[i][2];
        if (Z == 1)
            unite(X, Y);
        else
        {
            if (find(X) == find(Y))
                printf("Y\n");
            else
                printf("N\n");
        }
    }
}