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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= w; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] <= i)
                dp[i] += dp[i - a[j]] % MOD;
        }
    }
    cout << dp[w] % MOD << '\n';
    return 0;
}