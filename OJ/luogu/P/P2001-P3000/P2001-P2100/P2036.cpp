#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int N, ans = INT_MAX;
vector<int> acid, bitter;

// 选配料
// index 表示当前是第几个配料
// cur_a, cur_b 表示当前配料的酸度和苦度
// has_selected 标记是否选择了配料
void dfs(int index, int cur_a, int cur_b, bool has_selected)
{
    if (index == N)
    {
        if (has_selected)
        {
            ans = min(ans, abs(cur_a - cur_b));
        }
        return;
    }
    // 选当前（index）配料
    dfs(index + 1, cur_a * acid[index], cur_b + bitter[index], true);
    // 不选当前配料
    dfs(index + 1, cur_a, cur_b, has_selected);
}

int main()
{
    cin >> N;
    int a, b;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        acid.push_back(a);
        bitter.push_back(b);
    }
    dfs(0, 1, 0, false);
    printf("%d", ans);
    // cout << ans << '\n';
    return 0;
}

// =================================================

/*
    以下都是选“个数”的方案
    需要外层循环
*/

// #include <iostream>
// #include <vector>
// #include <utility>
// #include <cmath>
// #include <climits>
// #include <algorithm>
// using namespace std;

// int N;
// vector<int> acid, bitter;
// int ans = INT_MAX;

// void dfs(int n, int pos, int m, int current_acid, int current_bitter)
// {
//     if (pos == n)
//     {
//         ans = min(ans, abs(current_acid - current_bitter));
//         return;
//     }
//     for (int i = m; i < N; i++)
//         dfs(n, pos + 1, i + 1, current_acid * acid[i], current_bitter + bitter[i]);
// }

// int main()
// {
//     cin >> N;
//     int a, b;
//     for (int i = 0; i < N; i++)
//     {
//         cin >> a >> b;
//         acid.push_back(a);
//         bitter.push_back(b);
//     }
//     for (int i = 1; i <= N; i++)
//         dfs(i, 0, 0, 1, 0);
//     cout << ans << '\n';
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <utility>
// #include <cmath>
// #include <climits>
// using namespace std;

// int N;
// vector<int> acid, bitter;
// vector<pair<int, int>> path;
// int ans = INT_MAX;

// void dfs(int n, int pos, int m)
// {
//     int sub, a_total = 1, b_total = 0;
//     // 两个特判，性能优化
//     if (n == 1)
//     {
//         for (int i = 0; i < N; i++)
//         {
//             sub = abs(acid[i] - bitter[i]);
//             if (sub < ans)
//                 ans = sub;
//         }
//         return;
//     }
//     if (n == N)
//     {
//         for (int i = 0; i < N; i++)
//         {
//             a_total *= acid[i];
//             b_total += bitter[i];
//         }
//         sub = abs(a_total - b_total);
//         if (sub < ans)
//             ans = sub;
//         return;
//     }
//     if (pos == n)
//     {
//         for (const auto &[a, b] : path)
//         {
//             a_total *= a;
//             b_total += b;
//         }
//         sub = abs(a_total - b_total);
//         if (sub < ans)
//             ans = sub;
//         return;
//     }
//     for (int i = m; i < N; i++)
//     {
//         path.push_back({acid[i], bitter[i]});
//         dfs(n, pos + 1, i + 1);
//         path.pop_back();
//     }
// }

// int main()
// {
//     cin >> N;
//     int a, b;
//     for (int i = 0; i < N; i++)
//     {
//         cin >> a >> b;
//         acid.push_back(a);
//         bitter.push_back(b);
//     }
//     for (int i = 1; i <= N; i++)
//         dfs(i, 0, 0);
//     cout << ans << '\n';
//     return 0;
// }