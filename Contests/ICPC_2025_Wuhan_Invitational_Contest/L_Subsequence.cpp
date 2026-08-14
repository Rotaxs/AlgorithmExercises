#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr.begin() + 1, arr.end());
    for (int l = 1; l <= n; l++)
    {
        int r = l;
        for (int m = l; m <= n; m++)
        {
            int target = 2 * arr[m] - arr[l];
            while (r + 1 <= n && arr[r + 1] <= target)
                r++;
            if (arr[r] == target)
            {
                int L = m - l;
                int R = r - m;
                ans = max(ans, min(L, R) * 2 + 1);
                if (L < R)
                    ans = max(ans, 2 * (L + 1));
                else if (L == R)
                    ans = max(ans, 2 * L);
                else
                    ans = max(ans, 2 * R);
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

// #include <bits/stdc++.h>

// void solve()
// {
//     int n;
//     std::cin >> n;

//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++)
//     {
//         std::cin >> a[i];
//     }

//     std::sort(a.begin() + 1, a.end());
//     int ans = 0;
//     for (int m = 1; m <= n; m++)
//     {
//         for (int l = m, r = m; l >= 1; l--)
//         {
//             int g = 2 * a[m] - a[l];
//             while (r < n && a[r + 1] <= g)
//             {
//                 r++;
//             }
//             if (a[r] == g)
//             {
//                 int L = m - l;
//                 int R = r - m;
//                 // 处理长度为奇数的情况
//                 ans = std::max(ans, 1 + 2 * std::min(L, R));
//                 // 偶数的情况，中位数按照定义会归类到左边
//                 if (R > L) // R >= L + 1
//                 {
//                     ans = std::max(ans, 2 * (L + 1));
//                 }
//                 else if (R == L) // 左边取 L - 1 个，L 表示包含中位数，这是为了凑偶数，但实际上长度肯定不如奇数的长度大
//                 {
//                     ans = std::max(ans, 2 * L);
//                 } // L > R，左边取 R - 1 个
//                 else
//                 {
//                     ans = std::max(ans, 2 * R);
//                 }
//             }
//         }
//     }
//     std::cout << ans << '\n';
// }

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     int t;
//     std::cin >> t;
//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }