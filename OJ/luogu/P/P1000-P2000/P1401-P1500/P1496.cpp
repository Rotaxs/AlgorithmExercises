

// ================ 用 stl，并去掉前缀和数组 ==============

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> PII;

const int N = 2 * 1e4 + 10;
int n;
PII range[N];
// vals[i] 表示第 i 个起火点/终点，vals 中共有 len 个元素
// vals[1] 是第一个，vals[len] 是最后一个
long long vals[N << 1];
int len = 0;
int diff[N << 1];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> range[i].first >> range[i].second;
        vals[++len] = range[i].first;
        vals[++len] = range[i].second;
    }
    sort(vals + 1, vals + 1 + len);
    // unique 返回去重后数组有效值的下一个元素的迭代器
    len = unique(vals + 1, vals + 1 + len) - (vals + 1);
    for (int i = 1; i <= n; i++)
    {
        int l = lower_bound(vals + 1, vals + 1 + len, range[i].first) - vals;
        int r = lower_bound(vals + 1, vals + 1 + len, range[i].second) - vals;
        // 构造差分数组
        diff[l]++;
        diff[r]--;
    }

    long long ans = 0;
    // cur_pre 有和 prefix[i] 一样的作用
    int cur_pre = 0;
    // 只需循环到 len - 1，vals[len] 不可能着火（右边是开区间）
    for (int i = 1; i < len; i++)
    {
        cur_pre += diff[i];
        if (cur_pre > 0)
            ans += vals[i + 1] - vals[i];
    }

    cout << ans << '\n';
    return 0;
}

// ================ 没有优化的代码 =================

// #include <iostream>
// #include <algorithm>
// #include <utility>
// using namespace std;

// typedef pair<int, int> PII;

// const int N = 2 * 1e4 + 10;
// int n;
// PII range[N];
// // vals[i] 表示第 i 个起火点/终点，vals 中共有 len 个元素
// // vals[1] 是第一个，vals[len] 是最后一个
// int vals[N << 1], len = 0;
// // prefix[i] != 0 表示从 vals[i] 到 vals[i + 1] 都在燃烧
// int diff[N << 1], prefix[N << 1] = {0};

// int get_rank(int x)
// {
//     int l = 0, r = len + 1;
//     while ((l + 1) != r)
//     {
//         int m = l + ((r - l) >> 1);
//         if (vals[m] <= x)
//             l = m;
//         else
//             r = m;
//     }
//     return l;
// }

// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> range[i].first >> range[i].second;
//         vals[++len] = range[i].first;
//         vals[++len] = range[i].second;
//     }
//     sort(vals + 1, vals + 1 + len);
//     int new_len = 1;
//     for (int i = 2; i <= len; i++)
//     {
//         if (vals[i] != vals[i - 1])
//             vals[++new_len] = vals[i];
//     }
//     len = new_len;
//     for (int i = 1; i <= n; i++)
//     {
//         int l = get_rank(range[i].first);
//         int r = get_rank(range[i].second);
//         // 构造差分数组
//         diff[l]++;
//         diff[r]--;
//     }

//     long long ans = 0;
//     for (int i = 1; i <= len; i++)
//     {
//         prefix[i] = prefix[i - 1] + diff[i];
//         if (prefix[i])
//             ans += vals[i + 1] - vals[i];
//     }

//     cout << ans << '\n';
//     return 0;
// }
