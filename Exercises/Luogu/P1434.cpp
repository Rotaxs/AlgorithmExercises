// ========= 纯 dp ============

#include <iostream>
#include <algorithm>
using namespace std;

struct Pos { int x, y; };

const int R = 110, C = 110;
int r, c;
int mat[R][C];
int ans = 0;
int moves[] = {-1, 0, 1, 0, -1};
// dp[i][j] 表示从 (i, j) 开始滑雪的最大滑坡长度
// 初步感知：dp 是依赖低处点的，因此填表时要先填入低海拔的值，然后用低海拔的值算出高海拔的值
int dp[R][C] = {0};
int inDegree[R][C];


int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> mat[i][j];
    
    // 初始化入度表
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            for (int d = 0; d < 4; d++)
            {
                int ni = i + moves[d];
                int nj = j + moves[d + 1];
                if (ni <= 0 || nj <= 0 || ni > r || nj > c)
                    continue;
                if (mat[ni][nj] >= mat[i][j])
                    continue;
                inDegree[i][j]++;
            }
        }
    }

    // [l, r) 表示队列元素
    int l = 0, r = 1;
    Pos q[R * C];

    // 入度为 0：说明没有更低的点 → 最低点
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (inDegree[i][j] == 0)
            {
                q[r++] = {i, j};
                dp[i][j] = 1;
            }
        }
    }

    while (l < r)
    {
        auto [x, y] = q[l++];
        ans = max(ans, dp[x][y]);
        for (int d = 0; d < 4; d++)
        {
            int nx = x + moves[d];
            int ny = y + moves[d + 1];
            if (nx <= 0 || ny <= 0 || nx > r || ny > c)
                continue;
            // 取比自己高的点
            if (mat[nx][ny] <= mat[x][y])
                continue;
            dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1);
            inDegree[nx][ny]--;
            if (inDegree[nx][ny] == 0)
                q[r++] = {nx, ny};
        }
    }
    cout << ans << '\n';
    return 0;
}

// ========= 记忆化搜索 =========

// #include <iostream>
// #include <algorithm>
// using namespace std;

// const int R = 110, C = 110;
// int r, c;
// int mat[R][C];
// int ans = 0;
// int moves[] = {-1, 0, 1, 0, -1};
// // dp[i][j] 表示从 (i, j) 开始滑雪的最大滑坡长度
// int dp[R][C] = {0};

// int dfs(int cr, int cc)
// {
//     if (dp[cr][cc] != 0) return dp[cr][cc];
//     // tmp 记录从 (nr, nc) 开始的最大滑坡长度
//     int tmp = 0;
//     // 往四个方向递归，找到 tmp 最大的一个方向
//     for (int i = 0; i < 4; i++)
//     {
//         int nr = cr + moves[i], nc = cc + moves[i + 1];
//         if (nr <= 0 || nc <= 0 || nr > r || nc > c)
//             continue;
//         if (mat[nr][nc] >= mat[cr][cc])
//             continue;

//         tmp = max(dfs(nr, nc), tmp);
//     }
//     return dp[cr][cc] = tmp + 1;
// }

// int main()
// {
//     cin >> r >> c;
//     for (int i = 1; i <= r; i++)
//     {
//         for (int j = 1; j <= c; j++)
//         {
//             cin >> mat[i][j];
//         }
//     }
//     for (int i = 1; i <= r; i++)
//     {
//         for (int j = 1; j <= c; j++)
//         {
//             ans = max(dfs(i, j), ans);
//         }
//     }
//     cout << ans << '\n';
//     return 0;
// }

// ========= 暴搜 ===========

// #include <iostream>
// #include <algorithm>
// using namespace std;

// const int R = 110, C = 110;
// int r, c;
// int mat[R][C];
// int ans = 0;
// int moves[] = {-1, 0, 1, 0, -1};

// void dfs(int cr, int cc, int len)
// {
//     int cnt = 0;
//     for (int i = 0; i < 4; i++)
//     {
//         int nr = cr + moves[i], nc = cc + moves[i + 1];
//         if (nr <= 0 || nc <= 0 || nr > r || nc > c)
//         {cnt++; continue;}
//         if (mat[nr][nc] >= mat[cr][cc])
//         {cnt++; continue;}
        
//         dfs(nr, nc, len + 1);
//     }
//     // 判断如果周围都比自己高，就走到头了
//     if (cnt == 4)
//     {
//         ans = max(ans, len);
//         return;
//     }
// }

// int main()
// {
//     cin >> r >> c;
//     for (int i = 1; i <= r; i++)
//     {
//         for (int j = 1; j <= c; j++)
//         {
//             cin >> mat[i][j];
//         }
//     }
//     for (int i = 1; i <= r; i++)
//     {
//         for (int j = 1; j <= c; j++)
//         {
//             dfs(i, j, 1);
//         }
//     }

//     cout << ans << '\n';
//     return 0;
// }