#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5 * 1e5 + 10;
int nums[N], vals[N], n, len;
int tree[N] = {0}; // 实际大小为 1 ~ len
long long ans = 0;

int lowbit(int x) { return x & -x; }

void add(int i, int v)
{
    while (i <= len)
    {
        tree[i] += v;
        i += lowbit(i);
    }
}

int sum(int i)
{
    int ret = 0;
    while (i >= 1)
    {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        vals[i] = nums[i];
    }
    sort(vals + 1, vals + 1 + n);
    len = unique(vals + 1, vals + 1 + n) - (vals + 1);
    for (int i = n; i >= 1; i--)
    {
        int r = lower_bound(vals + 1, vals + 1 + len, nums[i]) - vals;
        ans += sum(r - 1);
        add(r, 1);
    }
    cout << ans << '\n';
    return 0;
}

// ====================== 分治 =======================

/*
#include <iostream>
#include <cstring>
using namespace std;

const int N = 5 * 1e5 + 10;
int arr[N], tmp[N];

void merge(int l, int m, int r)
{
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
        // 将大数放左边
        // 这样在后面统计时，cnt 可以直接记录大数的个数
        tmp[k++] = arr[i] > arr[j] ? arr[i++] : arr[j++];
    while (i <= m)
        tmp[k++] = arr[i++];
    while (j <= r)
        tmp[k++] = arr[j++];
    memcpy(arr + l, tmp + l, sizeof(int) * (r - l + 1));
}

long long get_inversion(int l, int r)
{
    if (r == l)
        return 0;
    int m = l + ((r - l) >> 1);
    long long l_val = get_inversion(l, m);
    long long r_val = get_inversion(m + 1, r);
    long long merge_val = 0;
    // 统计 merge 的过程中产生的逆序对
    // cnt 表示 arr 中从 l 到 i比 arr[j] 大的数的个数
    // 因此，指针 i 每往右移，cnt++
    // 而指针 j 每往右移，cnt 不变
    int i = l, j = m + 1, cnt = 0;
    for (; j <= r; j++)
    {
        for (; i <= m && arr[i] > arr[j]; i++)
            cnt++;
        merge_val += cnt;
    }
    merge(l, m, r);
    return l_val + r_val + merge_val;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << get_inversion(0, n - 1) << '\n';

    return 0;
}
*/