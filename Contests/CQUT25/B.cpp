// =================== dfs + 剪枝（tle）================

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 45;

// int n, m;
// int a[N];
// int ans = 0;

// void dfs(int p, int cur)
// {
//     if (cur > m) return;
//     if (p > n)
//     {
//         if (cur <= m)
//         {
//             ans++;
//         }
//         return;
//     }
//     dfs(p + 1, cur + a[p]);
//     dfs(p + 1, cur);
// }

// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     dfs(1, 0);
//     cout << ans << '\n';
//     return 0;
// }

// =========== 折半搜索 =================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int n;
ll m;
vector<ll> p;
vector<ll> suma, sumb;

// 搜索 p 数组 [l, r] 中的元素
// 每一步记录当前花费 cur_sum
// 得到在区间 [l, r] 内合法的消费 sums
void dfs(int l, int r, ll cur_sum, vector<ll> &sums)
{
    // 剪枝
    if (cur_sum > m) return;
    // 不能再搜了
    if (l > r)
    {
        // 记录区间 [l, r] 内的合法消费
        sums.push_back(cur_sum);
        return;
    }
    // 选第 l 本数
    dfs(l + 1, r, cur_sum + p[l], sums);
    // 不选第 l 本数
    dfs(l + 1, r, cur_sum, sums);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    p.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    int mid = n >> 1; // 等价与 n / 2
    dfs(1, mid, 0, suma);
    dfs(mid + 1, n, 0, sumb);

    ll ans = 0;

    // 组合两个部分的合法消费 suma 和 sumb
    // 暴力 （tle）
    // for (ll a : suma)
    // {
    //     for (ll b : sumb)
    //     {   
    //         if (a + b <= m)
    //             ans++;
    //     }   
    // }

    // 二分
    // sort(sumb.begin(), sumb.end());
    // for (ll val : suma)
    // {
    //     // 固定 suma 中的某个数 val
    //     // 在 sumb 中查找小于等于 m - val 的最大值的索引 i
    //     // 由于 sumb 已经排序，所以可以二分，并且只要 i 位置的数满足，那么 i 前面的数也满足
    //     ans += upper_bound(sumb.begin(), sumb.end(), m - val) - sumb.begin();
    // }

    // 双指针（最优解）
    sort(suma.begin(), suma.end());
    sort(sumb.begin(), sumb.end());
    // suma 从头开始遍历，sumb 从尾开始遍历
    int i = 0, j = sumb.size() - 1;
    while (i < suma.size() && j >= 0)
    {
        // 只要 sumb[j] 能满足，那么 sumb[0 ~ j] 都满足
        if (suma[i] + sumb[j] <= m)
        {
            ans += j + 1;
            i++;
        }
        // sumb[j] 不满足，那么 suma[i ~ end] 都不满足，所以向左移动 j 指针
        else
        {
            j--;
        }
    }

    cout << ans << '\n';

    return 0;
}