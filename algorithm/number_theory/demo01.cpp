/**
 * 计算n个数的gcd
 */

#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}

// int n_gcd(int num[], int size)
// {
//     int ans = num[0];
//     for (int i = 1; i < size; i++)
//     {
//         ans = gcd(ans, num[i]);
//     }
//     return ans;
// }

// int n_gcd(int nums[], int n)
// {
//     int m = 1e-8;
//     int ans = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (nums[i] > m) m = nums[i];
//     }
//     vector<int> factors(m + 1, 0);
//     for (int i = 0; i < n; i++)
//     {
//         int a = nums[i];
//         for (int j = 1; j <= a / j; j++)
//         {
//             if (a % j == 0) factors[j]++;
//             if (j != a / j) factors[a / j]++;
//         }
//     }
//     for (int i = m; i >= 1; i--)
//     {
//         if (factors[i] == n)
//         {
//             ans = i;
//             break;
//         }
//     }
//     return ans;
// }

int find_max_k_gcd(const vector<int> &nums, int k)
{
    if (nums.empty() || k < 1) return 0;
    // 记录最大值
    int M = 1e-8;
    for (int x : nums) M = max(M, x);
    // 统计每个数出现的次数
    vector<int> count(M + 1, 0);
    for (int x : nums) count[x]++;
    // 枚举 gcd：只要满足有超过 k 个数是 i 的倍数，i 就是 k_gcd
    for (int i = M; i >= 1; i--)
    {
        // 统计 i 的倍数的个数
        int cnt = 0;
        for (int j = i; j <= M; j += i)
        {
            cnt += count[j];
            if (cnt >= k) return i;
        }
    }
    return 1;
}

int main()
{
    // int nums[3] = {6, 12, 18};
    // cout << n_gcd(nums, 3) << endl;
    vector<int> nums = {6, 12, 18};
    cout << find_max_k_gcd(nums, 3) << '\n';
    return 0;
}
