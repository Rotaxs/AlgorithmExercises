#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 2 * 1e4 + 10;

int l[N], r[N];
// dp[i][0] 表示到达第 i 行的左端点（走完第 i 行，穿过线段）的最小路径长度
// dp[i][1] 表示到达第 i 行的右端点（走完第 i 行，穿过线段）的最小路径长度
// dp[i][0] = min(dp[i - 1][0] + dis(l[i - 1], r[i]) + dis[r[i], l[i]] + 1, dp[i - 1][1] + dis(r[i - 1], r[i]) + dis(r[i], l[i]) + 1)
int dp[N][3];

int dis(int l, int r) { return abs(r - l); }

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    // 第一行必须走完整个线段 [l1, r1]
    dp[1][0] = dis(1, r[1]) + dis(r[1], l[1]); // 先去右再回左
    dp[1][1] = dis(1, r[1]);                   // 直接去右（途中已过左）
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + dis(l[i - 1], r[i]) + dis(r[i], l[i]) + 1, dp[i - 1][1] + dis(r[i - 1], r[i]) + dis(r[i], l[i]) + 1);
        dp[i][1] = min(dp[i - 1][0] + dis(l[i - 1], l[i]) + dis(l[i], r[i]) + 1, dp[i - 1][1] + dis(r[i - 1], l[i]) + dis(l[i], r[i]) + 1);
    }
    cout << min(dis(l[n], n) + dp[n][0], dis(r[n], n) + dp[n][1]) << '\n';
    return 0;
}