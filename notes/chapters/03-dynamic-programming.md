# 动态规划

## 线性 DP

### 子数组最大累加和

- **时间复杂度**：$O(n)$
- **空间复杂度**：$O(n)$；滚动变量优化后为 $O(1)$
- **状态**：$dp[i]$ 表示以 $a[i]$ 结尾的最大子数组和

$$
dp[i] = \max(dp[i - 1] + a[i], a[i]),\qquad dp[1] = a[1]
$$

```cpp
const int N = 2 * 1e5 + 10;
int n, dp[N];

int main() {
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[1] = a[1];
    int ans = dp[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
        ans = max(dp[i], ans);
    }
    cout << ans << '\n';
    return 0;
}
```

注意到 $dp$ 只受上一个状态的影响，所以可以空间压缩

```cpp
int n;

int main() {
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int sum = a[1];
    int ans = a[1];
    for (int i = 2; i <= n; i++) {
        sum = max(a[i], sum + a[i]);
        ans = max(sum, ans);
    }
    cout << ans << '\n';
    return 0;
}
```

## 背包 DP

### 0-1 背包

- **时间复杂度**：$O(nC)$
- **空间复杂度**：$O(nC)$；滚动数组优化后为 $O(C)$
- **状态**：$dp[i][j]$ 表示前 $i$ 个物品在容量不超过 $j$ 时的最大价值

$$
dp[i][j] = \max(dp[i - 1][j], dp[i - 1][j - cost[i]] + val[i])
$$

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= c; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j >= cost[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + val[i]);
    }
}
```
空间压缩时容量必须倒序枚举，避免同一物品被重复选取。

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = c; j >= cost[i]; j--)
        dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
}
```
