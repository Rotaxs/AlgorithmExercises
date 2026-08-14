#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
// 如果当前有 w - v[i] 那么到达 w 还需要一张面额为 v[i] 的纸币，即结果加 1
// 如果能直到获取 w - v[i] 需要的纸币数量，就可以直到获取 w 需要的纸币数量
// 设 dp[i] 表示获取 i 元需要的最少纸币数量
// dp[i] = min_{1 <= j <= n}(dp[i - v[j]] + 1);
// 然而考虑到下标不能为负数，因此
// dp[i] = min_{v[j] <= i}(dp[i - v[j]] + 1)
// 转化为递推式
// dp[i] = min(dp[i], dp[i - v[j]] + 1)
int dp[10010] = {0};
int value[1010];

int main()
{
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) cin >> value[i];
    for (int i = 0; i <= w; i++) dp[i] = INF;
    dp[0] = 0;
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (value[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - value[j]] + 1);
            }
        }
    }
    cout << dp[w] << '\n';
    return 0;
}
