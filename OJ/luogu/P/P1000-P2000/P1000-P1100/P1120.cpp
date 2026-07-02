#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 70;
int a[N];
bool vis[N];
int n;
int sum = 0, maxn = 0;
int len, cnt;

// k 表示当前在处理第几根原木棒
// last 表示搜第 k 根原木棒的段的开始值
// rest 第 k 根原木棒还差多少
bool dfs(int k, int last, int rest)
{
    // cnt 根原木棒都找到了
    if (k > cnt) return true;
    // 第 k 根原木棒找到了，开始拼下一根
    if (!rest) return dfs(k + 1, 1, len);
    for (int i = last; i <= n; i++)
    {
        // 基础剪枝
        if (vis[i] || a[i] > rest) continue;
        vis[i] = true;
        if (dfs(k, i + 1, rest - a[i])) return true;
        vis[i] = false;
        // 剪枝 2：如果第一根就失败了，直接结束
        if (rest == len) return false;
        // 剪枝 3：如果 a[i] 作为最后一根都失败了（在拼第 k 根之后的木棒发现错误）
        // 比如 5 不行，但是后面还有 3 2，如果继续搜，搜到 3 2（算到第 k 根），那么后面的木棒就要用到 5，但是本来 3 2 凑后面都不行了，5 就更不行了
        if (rest == a[i]) return false;
        // 剪枝 4：a[i] 不行，那么与 a[i] 相同的也不行
        while (i + 1 <= n && a[i + 1] == a[i]) i++;
    }
    return false;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        maxn = max(maxn, a[i]);
    }
    // 优化，先处理长的，这样 rest 会更快的到 0，从而完成保留或回溯
    sort(a + 1, a + 1 + n, greater<int>());
    // 遍历原始长度
    for (len = maxn; len <= sum; len++)
    {
        // 剪枝 1：原始长度必须整除总长度
        if (sum % len != 0) continue;
        // 原木棒又 cnt 根
        cnt = sum / len;
        memset(vis, 0, sizeof(vis));
        if (dfs(1, 1, len))
        {
            cout << len << '\n';
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();

    return 0;
}