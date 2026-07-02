/**
 * 20260305 第三次做
 * 前面当 k 满足条件时用 exit 退出程序太不优雅了
 * 改一个迭代的版本
 */
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 5 * 1e6 + 10;
int arr[N];
int n, k;

PII partition(int l, int r, int pivot)
{
    int m = l;
    while (m <= r)
    {
        if (arr[m] < pivot)
            swap(arr[l++], arr[m++]);
        else if (arr[m] == pivot)
            m++;
        else
            swap(arr[r--], arr[m]);
    }
    return {l, r};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans;
    int l = 0, r = n - 1;
    while (l <= r)
    {
        PII bound = partition(l, r, arr[l + rand() % (r - l + 1)]);
        int left = bound.first, right = bound.second;
        if (k < left)
            r = left - 1;
        else if (k > right)
            l = right + 1;
        else
        {
            ans = arr[k];
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 20260304 第二次做
 * 设定一个基准值 pivot，将数组分为两部分，左部分全 < pivot，右部分全 > pivot
 * 这时 = pivot 会有一个下界 left 和一个上界 right
 * 当 k < left 时，说明第 k 小的数在左部分
 * 当 k > right 时，说明第 k 小的数在右部分
 * 否则，第 k 小的数就是 pivot
 */

/*
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 5 * 1e6 + 10;
int arr[N];
int n, k;

PII partition(int l, int r, int pivot)
{
    int m = l;
    while (m <= r)
    {
        if (arr[m] < pivot)
            swap(arr[l++], arr[m++]);
        else if (arr[m] == pivot)
            m++;
        else
            swap(arr[r--], arr[m]);
    }
    return {l, r};
}

void quick_sort(int l, int r)
{
    if (l >= r)
        return;
    int pivot = arr[l + rand() % (r - l + 1)];
    PII bound = partition(l, r, pivot);
    int left = bound.first, right = bound.second;
    if (k < left)
        quick_sort(l, left - 1);
    else if (k > right)
        quick_sort(right + 1, r);
    else
    {
        cout << arr[k] << '\n';
        exit(0);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quick_sort(0, n - 1);

    return 0;
}
*/

/*
 * 20260304 第一次做
 * 直接排序输出索引对应的值
 */

/*
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 5 * 1e6 + 10;
int arr[N], tmp[N];

void merge(int l, int m, int r)
{
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
        tmp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    while (i <= m)
        tmp[k++] = arr[i++];
    while (j <= r)
        tmp[k++] = arr[j++];
    memcpy(arr + l, tmp + l, sizeof(int) * (r - l + 1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int l, r, m;
    for (int step = 1; step < n; step <<= 1)
    {
        l = 0;
        while (l < n)
        {
            m = l + step - 1;
            if (m + 1 >= n)
                break;
            r = min(n - 1, l + (step << 1) - 1);
            merge(l, m, r);
            l = r + 1;
        }
    }

    cout << arr[k] << '\n';

    return 0;
}

*/