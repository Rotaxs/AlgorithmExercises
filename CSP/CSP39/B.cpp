#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 210;
int mat[N][N];
bool target[5][9] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 0, 0}
};
vector<pair<int, int>> rgs;
int pre[70000];

void get_k_range(int x, int y, int &maxn, int &minn)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (target[i][j]) minn = min(minn, mat[x + i][y + j]);
            else maxn = max(maxn, mat[x + i][y + j]);
        }
    }
}

void solve()
{
    int n, l; cin >> n >> l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin >> mat[i][j];;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int maxn = -1, minn = 1e6;
            get_k_range(i, j, maxn, minn);
            if (maxn == -1 || minn == 1e6) continue;
            if (maxn + 1 <= minn)
                rgs.push_back({maxn + 1, minn});
        }
    }
    for (auto [le, ri] : rgs)
    {
        pre[le]++;
        pre[ri + 1]--;
    }
    for (int i = 1; i <= l; i++)
    {
        pre[i] += pre[i - 1];
        if (pre[i] != 0)
            cout << i << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

// =============================
// 枚举 k 80pt

// #include <bits/stdc++.h>
// using namespace std;

// string target[5] = {
//     "*********",
//     "*--*--*-*",
//     "*--*****-",
//     "*----**--",
//     "*******--"
// };

// const int L = 65537;
// const int N = 210;
// int mat[N][N];
// vector<int> nums;

// bool cmp(int x, int y, int k)
// {
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < 9; j++)
//         {
//             char c = '-';
//             if (mat[x + i][y + j] >= k) c = '*';
//             if (c != target[i][j])
//                 return false;
//         }
//     }
//     return true;
// }

// bool check(int n, int k)
// {
//     for (int sx = 0; sx <= n - 4; sx++)
//         for (int sy = 0; sy <= n - 8; sy++)
//             if (cmp(sx, sy, k))
//                 return true;
//     return false;
// }

// void solve()
// {
//     int n, l; cin >> n >> l;
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             cin >> mat[i][j], nums.push_back(mat[i][j]);
//     for (int k = 0; k <= l; k++)
//     {
//         if (check(n, k))
//         {
//             cout << k << '\n';
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     solve();
//     return 0;
// }