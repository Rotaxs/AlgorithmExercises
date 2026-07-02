#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e4 + 10;
// arr[i] 表示坐标为 i 位置的正方体的高度
// pre[i] 表示坐标为 0 ~ i 位置的正方体的高度的最大值
// suf[i] 表示坐标为 i ~ n - 1 位置的正方体的高度的最大值
int arr[N], pre[N], suf[N];
int n, ans = 0;

void print_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        // 预处理 pre[]
        pre[i] = i == 0 ? arr[i] : max(arr[i], pre[i - 1]);
        // 预处理 suf[]
        suf[n - 1 - i] = i == 0 ? arr[n - 1] : max(arr[n - i - 1], suf[n - i]);
    }
    // 两边肯定无法积水
    // for (int i = 1; i < n - 1; i++)
    //     ans += max(min(pre[i - 1], suf[i + 1]) - arr[i], 0);

    int l = 1, r = n - 2;
    int lmax = arr[0], rmax = arr[n - 1];
    while (l <= r)
    {
        lmax = max(lmax, arr[l - 1]);
        rmax = max(rmax, arr[r + 1]);
        if (lmax <= rmax)
            ans += max(lmax - arr[l++], 0);
        else if (lmax > rmax)
            ans += max(rmax - arr[r--], 0);
        // else
        // {
        //     ans += max(lmax - arr[l++], 0);
        //     ans += max(rmax - arr[r--], 0);
        // }
    }

    cout << ans << '\n';

    return 0;
}