/**
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。
 * 如果不存在符合条件的连续子数组，返回 0。
 */
/*
    输入：s=7, nums={2, 3, 1, 2, 4, 3}
    输出：2
    解释：{4, 3}是满足条件的最小连续子数组
*/
#include <iostream>
using namespace std;

int main()
{
    int s = 7;
    int nums[] = {2, 3, 1, 2, 4, 3};
    int sz = sizeof(nums) / sizeof(nums[0]);

    int l = 0, r = 0;
    int start = 0, minlen = sz + 1;
    int summation = 0;

    while (r < sz)
    {
        summation += nums[r];
        r++;
        // 使用循环，积极地移动左指针，使得长度更小
        while (summation >= s)
        {
            if (r - l < minlen)
            {
                start = l;
                minlen = r - l;
            }
            summation -= nums[l];
            l++;
        }
    }

    int res = minlen == sz + 1 ? 0 : minlen;
    cout << res << endl;
}
