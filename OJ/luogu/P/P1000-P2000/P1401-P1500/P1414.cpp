#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve()
{
    int n;
    cin >> n;
    int M = 0;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        M = max(nums[i], M);
    }

    vector<int> freq(M + 1, 0);
    for (int x : nums) freq[x]++;

    // 每个数至少有一个公因数为 1
    // ans[k] 表示 k 个数的最大公因数
    vector<int> ans(n + 1, 1);
    for (int i = M; i >= 1; i--)
    {
        // 统计 i 为因子出现的次数
        int cnt = 0;
        for (int j = i; j <= M; j += i)
            cnt += freq[j];
        // cnt 个数都有因子 i，说明这 cnt 个数的最大公因数就是 i
        // 即 ans[cnt] = i，取 i 的最大值作为 cnt 个数的最大公因数
        // 由于 i 是从最大的数开始遍历，则第一次更新 ans[cnt] 的 i 就是最大的 i
        if (cnt > 0 && ans[cnt] == 1)
            ans[cnt] = i;
    }
    // 将 ans 数组补充完整
    // 如果 c + 1 个数的最大公因数是 x，那么 c 个数的最大公因数至少也是 x
    int cur = 1;
    for (int i = n; i >= 1; i--)
    {
        cur = max(cur, ans[i]);
        ans[i] = cur;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
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