#include <bits/stdc++.h>
using namespace std;

const int MAXW = 1e4 + 10;
const int MAXN = 1e3 + 10;
const int MOD = 1e9 + 7;

int a[MAXN] = {0};
// dp[i] 凑出 i 元的支付方式的数量
// dp[i] = sum_{valid j}(dp[i - a[j]])
long long dp[MAXW] = {0};

int main()
{
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++) // TODO
        cin >> a[i];
    // 支付 0 元的方案数只有 1 中，即选择 0 张纸币支付
    dp[0] = 1;
    // 对比 P2840
    // j 枚举纸币面额
    for (int j = 0; j < n; j++)
    {
        // i 枚举支付金额
        // 相当于先将某一纸币累加到目标金额，表示已选择
        // 后面就不会再使用选择过的纸币了
        for (int i = a[j]; i <= w; i++)
        {
            dp[i] += dp[i - a[j]] % MOD;
        }
    }
    cout << dp[w] % MOD << '\n';
    return 0;
}