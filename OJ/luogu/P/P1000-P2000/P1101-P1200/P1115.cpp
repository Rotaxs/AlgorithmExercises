#include <iostream>
#include <vector>
using namespace std;

const int N = 2 * 1e5 + 10;
int n;

int main()
{
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int sum = a[1];
    int ans = a[1];
    for (int i = 2; i <= n; i++)
    {
        sum = max(a[i], sum+ a[i]);
        ans = max(sum, ans);
    }
    cout << ans << '\n';
    return 0;
}

// =========== dp ==============

// #include <iostream>
// #include <vector>
// using namespace std;

// const int N = 2 * 1e5 + 10;
// int n;
// // dp[i] 表示以第 i 个元素为结尾的子数组的最大字段和
// int dp[N];

// int main()
// {
//     cin >> n;
//     vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     dp[1] = a[1];
//     int ans = dp[1];
//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = max(a[i], dp[i - 1] + a[i]);
//         ans = max(dp[i], ans);
//     }
//     cout << ans << '\n';
//     return 0;
// }


// ============== 前缀和 ==========

// #include <iostream>
// #include <climits>
// #include <algorithm>
// using namespace std;

// const int N = 2 * 1e5 + 10;
// int n;
// long long sum = 0; // 前缀和
// int arr[N];

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n;
//     long long min_pre = 0, ans = LLONG_MIN;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> arr[i];
//         sum += arr[i];
//         ans = max(ans, sum - min_pre);
//         min_pre = min(min_pre, sum);
//     }

//     cout << ans << '\n';

//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// #include <climits>

// using namespace std;

// const int N = 200010;
// long long arr[N], pre[N];

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     if (!(cin >> n))
//         return 0;

//     pre[0] = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> arr[i];
//         pre[i] = pre[i - 1] + arr[i];
//     }

//     long long max_sum = LLONG_MIN;
//     long long min_prefix = 0; // 记录 pre[0] 到 pre[i-1] 之间的最小值

//     for (int i = 1; i <= n; i++)
//     {
//         max_sum = max(max_sum, pre[i] - min_prefix);
//         min_prefix = min(min_prefix, pre[i]);
//     }

//     cout << max_sum << endl;

//     return 0;
// }