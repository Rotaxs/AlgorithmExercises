#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int tmp[1024];

// inline void merge(int *a, int l, int m, int r)
// {
//     int i = l, j = m + 1, k = l;
//     for (; i <= m && j <= r; k++)
//     {
//         if (a[i] < a[j])
//             tmp[k] = a[i++];
//         else
//             tmp[k] = a[j++];
//     }
//     for (; i <= m; i++, k++)
//         tmp[k] = a[i];
//     for (; j <= r; j++, k++)
//         tmp[k] = a[j];
//     memcpy(a + l, tmp + l, sizeof(int) * (r - l + 1));
// }

void merge(int *a, int l, int m, int r)
{
    int tmp[1024];
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
    {
        // 这里 <= 保证排序的稳定性
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    memcpy(a + l, tmp + l, sizeof(int) * (r - l + 1));
}

void merge_sort_recursive(int *a, int l, int r)
{
    if (l == r)
        return;
    int m = l + ((r - l) >> 1);
    merge_sort_recursive(a, l, m);
    merge_sort_recursive(a, m + 1, r);
    merge(a, l, m, r);
}

void merge_sort_iterative(int *a, int len)
{
    int l, m, r;
    for (int step = 1; step < len; step <<= 1)
    {
        l = 0;
        // 分组，每组有两部分，分别为 [l, l + step - 1] 和 [l + step, r]
        // 每部分有 step 个元素
        while (l < len)
        {
            m = l + step - 1;
            // 表示某一组的左部分已经将剩下的元素包含完全了
            // 即当前组已经没有右侧
            if (m + 1 >= len)
                break;
            // 如果有右侧，就计算右侧的索引
            r = min(l + (step << 1) - 1, len - 1);
            merge(a, l, m, r);
            // 进入下一组 merge
            l = r + 1;
        }
    }
}

int main()
{
    int arr[] = {1, 3, 2, 4, 1, 4, 6, 7, 2, 1};
    // merge_sort_recursive(arr, 0, 9);
    merge_sort_iterative(arr, 10);
    for (int a : arr)
        cout << a << ' ';
    return 0;
}