// ============== 用“已经”状态代替“剩下”状态 使 dp 更直观 ===========

#include <iostream>
using namespace std;

const int N = 20;
int n;
// dp[i][j] 表示已经有 i 个元素入栈，j 个元素出栈的方案数
int dp[N][N];

int main()
{
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][n] << '\n';
    return 0;
}

// =============== 记忆化搜索改 dp ===============

// #include <iostream>
// using namespace std;

// const int N = 20;
// int n;
// int dp[N][N];

// int main()
// {
//     cin >> n;
//     dp[0][0] = 1;
//     // pre 代表栈外剩余元素
//     for (int pre = 0; pre <= n; pre++)
//     {
//         // mid 代表栈内现有（剩余）元素
//         for (int mid = 0; mid <= n; mid++)
//         {
//             if (pre == 0 && mid == 0)
//                 continue;

//             // 出栈
//             if (mid > 0)
//                 dp[pre][mid] += dp[pre][mid - 1];
//             // 入栈
//             if (pre > 0 && mid < n)
//                 dp[pre][mid] += dp[pre - 1][mid + 1];
//         }
//     }
//     cout << dp[n][0] << '\n';
//     return 0;
// }

// ==================== 记忆化 dfs =====================

// #include <iostream>
// #include <cstring>
// using namespace std;

// typedef long long ll;
// const int N = 20;
// ll memo[N][N];
// int n;

// long long dfs(int pre, int mid)
// {
//     // base case 表示找到了一种解法
//     if (pre == 0 && mid == 0)
//         return 1;
//     if (memo[pre][mid] != -1)
//         return memo[pre][mid];
//     long long cnt = 0;

//     // 加上先入栈的情况
//     if (pre > 0)
//         cnt += dfs(pre - 1, mid + 1);
//     // 在加上后出栈的情况
//     if (mid > 0)
//         cnt += dfs(pre, mid - 1);
//     return memo[pre][mid] = cnt;
// }

// int main()
// {
//     cin >> n;
//     memset(memo, -1, sizeof memo);
//     cout << dfs(n, 0) << '\n';
//     return 0;
// }

// ================== 无剪枝 无记忆化 dfs tle ===============

// #include <iostream>
// using namespace std;

// int ans = 0;
// int n;

// void dfs(int size, int many)
// {
//     if (size == 0 && many == 0)
//     {
//         ans++;
//         return;
//     }
//     if (size > 0)
//         dfs(size - 1, many + 1);
//     if (many > 0)
//         dfs(size, many - 1);
// }

// int main()
// {
//     cin >> n;
//     dfs(n, 0);
//     cout << ans << '\n';
//     return 0;
// }