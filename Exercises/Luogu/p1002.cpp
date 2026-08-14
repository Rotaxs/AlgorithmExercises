// ==================== 2026.1.25 第一次复习 ====================
#include <iostream>
using namespace std;

int main()
{

    return 0;
}

// ============================================
// #include <iostream>

// using namespace std;

// typedef long long LL;
// LL n, m, xh, yh, f[30][30] = {0};

// int main()
// {
//     cin >> n >> m >> xh >> yh;
//     n += 2;
//     m += 2;
//     xh += 2;
//     yh += 2;
//     LL pand[9][2] = {{xh, yh}, {xh - 2, yh - 1}, {xh - 2, yh + 1}, {xh - 1, yh - 2}, {xh - 1, yh + 2}, {xh + 1, yh - 2}, {xh + 1, yh + 2}, {xh + 2, yh - 1}, {xh + 2, yh + 1}};

//     f[2][1] = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         for (int j = 2; j <= m; j++)
//         {
//             bool flag = true;
//             for (int p = 0; p < 9; p++)
//             {
//                 if ((i == pand[p][0]) && (j == pand[p][1]))
//                 {
//                     flag = false;
//                     break;
//                 }
//             }
//             if (flag)
//                 f[i][j] = f[i - 1][j] + f[i][j - 1];
//         }
//     }
//     cout << f[n][m] << endl;

//     return 0;
// }
