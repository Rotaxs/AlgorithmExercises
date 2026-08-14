
#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 210;

int f[N][N];

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            f[i][j] = (i == j ? 0 : inf);

    while (m--)
    {
        int i, j, w; cin >> i >> j >> w;
        f[i][j] = f[j][i] = w;
    }

    int q; cin >> q;
    int k = 0;
    while (q--)
    {
        int x, y, z; cin >> x >> y >> z;

        for (; k < n && t[k] <= z; k++)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        }

        if (t[x] > z || t[y] > z || f[x][y] == inf) cout << -1 << '\n';
        else cout << f[x][y] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// const int inf = 0x3f3f3f3f;
// const int N = 210;

// int f[N][N][N];

// void floyd(int n)
// {
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             f[0][i][j] = min(f[0][i][j], f[0][i][0] + f[0][0][j]);
//     for (int k = 1; k < n; k++)
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < n; j++)
//                 f[k][i][j] = min(f[k - 1][i][j], f[k - 1][i][k] + f[k - 1][k][j]);
// }

// void solve()
// {
//     int n, m; cin >> n >> m;
//     vector<int> ti(n);
//     for (int i = 0; i < n; i++) cin >> ti[i];
//     for (int k = 0; k < n; k++)
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < n; j++)
//                 f[k][i][j] = (i == j ? 0 : inf);
//     while (m--)
//     {
//         int i, j, w; cin >> i >> j >> w;
//         f[0][i][j] = f[0][j][i] = w;   
//     }
//     floyd(n);

//     int q; cin >> q;
//     while (q--)
//     {
//         int x, y, t; cin >> x >> y >> t;
//         int k = upper_bound(ti.begin(), ti.end(), t) - ti.begin() - 1;
//         if (ti[x] > t || ti[y] > t || f[k][x][y] == inf) cout << -1 << '\n';
//         else cout << f[k][x][y] << '\n';
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
    
//     // int t;
//     // cin >> t;
//     // while (t--) solve();

//     solve();
    
//     return 0;
// }