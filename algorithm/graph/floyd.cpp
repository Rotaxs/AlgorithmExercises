#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int f[N][N];

void floyd(int n)
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
}

int main()
{

    return 0;
}