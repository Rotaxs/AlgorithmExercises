#include <iostream>
using namespace std;

const int N = 4001;
const long long MOD = 2147483648L;
int n;
// 参考 P1025
// dp[i][j] 表示数 i 的拆分为 j 个数的和的方案数
// dp[i][j] = dp[i-1][j-1] + dp[i-j][j]
long long dp[N][N];

int main()
{
    cin >> n;
    // for (int i = 1; i < N; i++)
    // {
    //     dp[i][i] = 1;
    //     dp[i][1] = 1;
    // }

    dp[0][1] = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]) % MOD;
        }
    }

    long long res = 0;

    for (int i = 2; i <= n; i++)
    {
        res = (res + dp[n][i]) % MOD;
    }
    cout << res % MOD << endl;
    return 0;
}