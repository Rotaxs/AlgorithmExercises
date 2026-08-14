/**
 * 给出n个数，输出删掉任意一个元素或不删剩下的所有元素的gcd的最大值
 */
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}

int n_gcd(int nums[], int size)
{
    int ans = nums[0];
    for (int i = 1; i < size; i++)
    {
        ans = gcd(ans, nums[i]);
    }
    return ans;
}

void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ==============================================================================

/*
    分析：两个思考角度
        1. 依次删除数组中的元素，然后直接计算剩下元素的gcd
        2. 依次以某个元素为分界计算前缀gcd=pre和后缀gcd=suf，取gcd=gcd(pre, suf)，然后找到最大的gcd即可
*/

// 方案一：
// =============================================================================

vector<int> erase(int nums[], int size, int index)
{
    vector<int> new_nums;
    for (int i = 0; i < size; i++)
    {
        if (i != index)
            new_nums.push_back(nums[i]);
    }
    return new_nums;
}

int n_gcd_for_vector(vector<int> nums)
{
    int ans = nums[0];
    for (int e : nums)
    {
        ans = gcd(ans, e);
    }
    return ans;
}

int separate_gcd1(int nums[], int size)
{
    int max = n_gcd(nums, size);
    for (int i = 0; i < size; i++)
    {
        vector<int> new_nums = erase(nums, size, i);
        int temp_gcd = n_gcd_for_vector(new_nums);
        if (temp_gcd > max)
            max = temp_gcd;
    }
    return max;
}

// 方案二
// ======================================================================================

int separate_gcd2(int nums[], int size)
{
    int max = n_gcd(nums, size);
    int temp;
    for (int i = 1; i < size - 1; i++)
    {
        int pre = n_gcd(nums, i - 1);
        int suf = n_gcd(&nums[i + 1], size - (i + 1));
        temp = gcd(pre, suf);
        if (temp > max)
            max = temp;
    }
    return max;
}

// 方案二改进：方案二的时间复杂度为O(n^2)，考虑使用前缀和数组降低时间复杂度
// ======================================================================================

void create_prefix(int nums[], vector<int> &prefix, int size)
{
    prefix[0] = 0;
    for (int i = 0; i < size - 1; i++)
    {
        prefix[i + 1] = gcd(prefix[i], nums[i]);
    }
}

void create_suffix(int nums[], vector<int> &suffix, int size)
{
    suffix[size - 1] = 0;
    for (int i = size - 1; i > 0; i--)
    {
        suffix[i - 1] = gcd(suffix[i], nums[i]);
    }
}

int separate_gcd3(int nums[], int size)
{
    // 前缀gcd数组，pre[i] 表示0到i-1的元素的gcd，i>=1
    vector<int> pre(size);
    // 后缀gcd数组，suf[i] 表示i+1到size-1的元素的gcd，i<size-1
    vector<int> suf(size);
    create_prefix(nums, pre, size);
    create_suffix(nums, suf, size);

    // 当 i=0 时，gcd=suf[0]
    // 当 i=size-1 时，gcd=pre[size-1]
    // 否则 gcd = gcd(pre[i], suf[i])

    // 初始化 max，优先处理两个特殊情况
    int max = pre[size - 1] > suf[0] ? pre[size - 1] : suf[0];
    int temp;
    for (int i = 1; i < size - 1; i++)
    {
        temp = gcd(pre[i], suf[i]);
        if (temp > max)
            max = temp;
    }
    return max;
}

int main()
{
    int nums[] = {12, 15, 18};
    int size = sizeof(nums) / sizeof(nums[0]);
    cout << separate_gcd3(nums, size) << endl;

    return 0;
}