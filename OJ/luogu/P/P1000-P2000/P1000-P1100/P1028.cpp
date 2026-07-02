#include <iostream>
using namespace std;

/*

    dp[1] = 1
    dp[2] = 2
    dp[3] = 2
    dp[4] = 4
    dp[5] = 4 = 1 + dp[2] + dp[1]
    dp[6] = 6 = 1 + dp[3] + dp[2] + dp[1]
    dp[8] = 1 + dp[4] + dp[3] + dp[2] + dp[1]
*/

long long dp[1010] = {0};

int f[1010];

int dfs(int n)
{
    if (n == 1)
        return 1;
    if (f[n] != 0)
        return f[n];
    int ans = 1;
    for (int i = 1; i <= n / 2; i++)
        ans += dfs(i);
    f[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << dfs(n) << '\n';

    // dp[1] = 1;
    // dp[2] = 2;

    // for (int i = 3; i <= n; i++)
    // {
    //     dp[i] = 1;
    //     for (int j = 1; j <= i / 2; j++)
    //         dp[i] += dp[j];
    // }
    // cout << dp[n] << '\n';

    return 0;
}