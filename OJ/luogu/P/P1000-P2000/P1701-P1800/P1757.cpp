#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
const int M = 1010;
// dp[i] 表示背包容量不超过 i 的前提下的最大价值
int dp[M];

struct Item
{
    int a, b, c;
} items[N];

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> items[i].a >> items[i].b >> items[i].c;
    }
    sort(items + 1, items + 1 + n, [](const Item &a, const Item &b) { return a.c < b.c; });

    // i 表示组号，start表示组的起始位置，end 表示下一组的起始位置
    for (int i = 1, start = 1, end = 2; start <= n; i++)
    {
        // end 移动到下一组的起始位置
        while (end <= n && items[end].c == items[start].c)
            end++;

        // 这里 j 一直到 0，因为现在的 i 只能确定组，而不能确定每个物品的容量
        for (int j = m; j >= 0; j--)
        {
            // 取每组中容量不超过 j 时的价值最大的
            for (int k = start; k < end; k++)
            {
                if (j >= items[k].a)
                    dp[j] = max(dp[j], dp[j - items[k].a] + items[k].b);
            }
        }

        start = end++;
    }

    cout << dp[m] << '\n';
    return 0;
}

// #include <iostream>
// #include <algorithm>
// using namespace std;

// const int N = 1010;
// const int M = 1010;
// // dp[i][j] 表示考虑完前 i 组物品后，背包容量不超过 j 的前提下物品的最大价值
// int dp[N][M] = {0};

// struct Item
// {
//    int a, b, c;
// } items[N];

// int main()
// {   
//     int m, n;
//     cin >> m >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> items[i].a >> items[i].b >> items[i].c;
//     }
//     sort(items + 1, items + 1 + n, [](const Item &a, const Item &b){ return a.c < b.c; });

//     int teams = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (i == 1 || items[i].c != items[i - 1].c)
//             teams++;
//     }

//     // i 表示组号，start表示组的起始位置，end 表示下一组的起始位置
//     for (int i = 1, start = 1, end = 2; start <= n; i++)
//     {
//         // end 移动到下一组的起始位置
//         while (end <= n && items[end].c == items[start].c)
//             end++;
        
//         // 横向填表
//         for (int j = 1; j <= m; j++)
//         {
//             // 不选该组
//             dp[i][j] = dp[i - 1][j];
//             // 取每组中价值最大的
//             for (int k = start; k < end; k++)
//             {
//                 if (j >= items[k].a)
//                     dp[i][j] = max(dp[i][j], dp[i - 1][j - items[k].a] + items[k].b);
//             }
//         }

//         start = end++;
//     }
    
//     cout << dp[teams][m] << '\n';
//     return 0;
// }