#include <iostream>
#include <vector>
using namespace std;

int N, K;
int res = 0;
// vector<vector<int>> res;
// vector<int> path;

// void dfs(int n, int k, int m)
// {
//     if (k == K)
//     {
//         if (n >= m)
//         {
//             path.push_back(n);
//             res.push_back(path);
//             path.pop_back();
//         }
//         return;
//     }
//     for (int i = m; i < n; i++)
//     {
//         path.push_back(i);
//         dfs(n - i, k + 1, i);
//         path.pop_back();
//     }
// }

// void print_mat(vector<vector<int>> res)
// {
//     for (const auto &arr : res)
//     {
//         for (int i = 0; i < arr.size(); i++)
//         {
//             // cout << arr[i] << "+";
//             cout << arr[i] << (i == arr.size() - 1 ? "" : "+");
//         }
//         cout << "\n";
//     }
// }

// n 表示要拆分的整数，k 表示拆的当前拆第几个数，m 表示当前拆分的最小值
void dfs(int n, int k, int m)
{
    if (k == K)
    {
        if (n >= m)
        {
            res++;
        }
        return;
    }
    for (int i = m; i <= n; i++)
    {
        dfs(n - i, k + 1, i);
    }
}

int main()
{
    cin >> N >> K;
    dfs(N, 1, 1);
    // print_mat(res);
    cout << res << '\n';
    return 0;
}

// #include <iostream>
// #include <cstring>
// using namespace std;

// int n, k;
// const int N = 200;
// // dp[i][j] 表示 i 分成 j 个数的方案数
// // dp[i][j] = dp[i-1][j-1] + dp[i-j][j]
// // 有 1：i = 1 + (i-1)，不考虑 1，只需要将 i-1 拆分为 j-1 个数接口
// // 没 1：i = 1 + 1 + (i-2) （j = 3），只需要将所有数减 1 得到 i-j = 0 + 0 + (i-j)，接下来只要将 i-j 拆分成 j 个数即可
// // 基本情况 dp[i][i] = 1， dp[i][1] = 1，dp[i][j] = 0（当 i < j 时）
// int dp[N + 1][N + 1];

// int main()
// {
//     cin >> n >> k;
//     memset(dp, 0, sizeof(dp));
//     for (int i = 1; i <= n; i++)
//     {
//         dp[i][i] = 1;
//         dp[i][1] = 1;
//     }
//     dp[0][1] = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
//         }
//     }
//     cout << dp[n][k] << endl;

//     return 0;
// }