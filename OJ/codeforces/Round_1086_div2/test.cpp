#include <iostream>
using namespace std;

const int N = 110;
int t, n;
int mat[N][N];


void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mat[i][j];
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
        solve();

    return 0;
}