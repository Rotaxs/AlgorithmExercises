#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

// int arr[] = {5, 3, 6, 2, 4, 3, 5, 6, 7, 2, 9};
int two_way_partition_enhanced(int arr[], int l, int r)
{
    int pivot = arr[l];
    while (l < r) // l != r 只有当 l == r 时才会结束
    {
        while (l < r && arr[r] >= pivot)
            r--;
        arr[l] = arr[r];
        while (l < r && arr[l] <= pivot)
            l++;
        arr[r] = arr[l];
    }
    arr[l] = pivot;
    return l;
}

int two_way_partition(int arr[], int l, int r)
{
    // a - 1 表示对应的 pivot 的索引
    // 同时 a 也是两部分的边界（左部分的第一个元素的索引）
    // 通过不断扩充左部分（a++），即可在扩充的过程中最终确定边界
    // pivot_i 记录索引小于 a 的最后一个（任意一个） pivot 的位置
    int a = l, pivot_i = l;
    int pivot = arr[a];

    // i 不能从 l + 1 开始，否则最开始 a 指向的 pivot 会被换到后面
    // 即导致 a 在最开始时表示的就不是左部分的第一个元素的索引
    for (int i = l; i <= r; i++)
    {
        // arr[i] <= pivot 说明这个数应该在左部分
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[a]);
            if (arr[a] == pivot)
                pivot_i = a;
            // 左部分元素变多，扩充边界
            a++;
        }
    }
    swap(arr[pivot_i], arr[a - 1]);
    return a;
}

// 三路划分，返回基准值的下界和上界
PII three_way_partition(int arr[], int l, int r)
{
    // 用 l，r 维护基准值的上下边界
    // m 进行扫描
    int m = l;
    int pivot = arr[l];
    // 当 m > r 时，右边已经是全都大于 pivot 的数了
    while (m <= r)
    {
        // 小于基准值，换到左部分，并移动两个指针
        if (arr[m] < pivot)
            swap(arr[l++], arr[m++]);
        // 等于基准值，留在中间，继续扫描
        else if (arr[m] == pivot)
            m++;
        // 大于基准值，换到右部分
        // 这时从右边换过来的数还不知道其与基准值的关系
        // 因此这个数也得扫描，即 m 不动
        else
            swap(arr[r--], arr[m]);
    }
    return {l, r};
}

void quick_sort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    // note: 基准值用随机数能降低在特殊情况下的时间复杂度

    /* 二路划分  */
    // int m = two_way_partition_enhanced(arr, l, r);
    // // 分别对基准值的前半部分和后半部分（不包含基准值）快排
    // quick_sort(arr, l, m - 1);
    // quick_sort(arr, m + 1, r);

    /* 三路划分 */
    PII bound = three_way_partition(arr, l, r);
    int a = bound.first, b = bound.second;
    quick_sort(arr, l, a - 1);
    quick_sort(arr, b + 1, r);
}

void quick_sort(int arr[], int len)
{
    quick_sort(arr, 0, len - 1);
}

void print(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

// 求数组中第 k 小的数
int randomized_select(int arr[], int l, int r, int k)
{
    int left = l, right = r;
    while (left <= right)
    {
        PII bound = three_way_partition(arr, left, right);
        int low = bound.first, high = bound.second;
        if (k < low)
            right = low - 1;    
        else if (k > high)
            left = high + 1;
        else
            return arr[k];
    }
    return arr[l];
}

int main()
{
    int arr[] = {5, 3, 6, 2, 4, 3, 5, 6, 7, 2, 9};
    cout << randomized_select(arr, 0, 3, 1);
    return 0;
}