/**
 * 洛谷 P1149 火柴棒等式
 * https://www.luogu.com.cn/problem/P1149
 */

/*
    对称性处理
*/

#include <iostream>
#include <vector>
using namespace std;

const int N = 2005;
int matches_per_num[N] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, ans = 0;
vector<int> path;

void init_matches()
{
    for (int i = 10; i < N; i++)
    {
        matches_per_num[i] = matches_per_num[i / 10] + matches_per_num[i % 10];
    }
}

void dfs(int pos, int start_val, int current_matches)
{
    if (pos == 3)
    {
        int a = path[0];
        int b = path[1];
        int c = a + b;

        // C 的火柴数检查
        if (c < N && matches_per_num[c] == n - current_matches)
        {
            if (a == b)
                ans += 1; // A = B 的情况，只算一种
            else
                ans += 2; // A < B 的情况，算上 A+B 和 B+A 两种
        }
        return;
    }

    for (int i = start_val; i < 1000; i++)
    {
        // 剪枝：当前火柴 + 剩下的数字(至少1个)最小火柴数 > n
        // 剩下的数字是 B 或 C，最少用 2 根
        if (current_matches + matches_per_num[i] > n - 2)
            continue;

        path.push_back(i);
        // 如果是选第一个数(pos=1)，选完后下一层从当前 i 开始(保证 A <= B)
        // 如果是选第二个数(pos=2)，递归会进入 pos=3 的逻辑
        dfs(pos + 1, i, current_matches + matches_per_num[i]);
        path.pop_back();
    }
}

int main()
{
    cin >> n;
    // 预处理
    if (n <= 10)
    {
        cout << 0 << endl;
        return 0;
    }
    n -= 4; // 减去 + 和 =
    init_matches();

    // 从第1个数开始选，初始火柴用量为0，起始数字从0开始
    dfs(1, 0, 0);

    cout << ans << endl;
    return 0;
}

// =================================================

/*
    空间换时间
*/

// #include <iostream>
// #include <vector>
// using namespace std;

// const int N = 2000;
// int matches_per_num[N] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
// vector<int> path;
// // vector<vector<int>> res;
// int ans = 0;
// int n;

// void init_matches()
// {
//     for (int i = 10; i < N; i++)
//     {
//         int tmp = i;
//         while (tmp)
//         {
//             matches_per_num[i] += matches_per_num[tmp % 10];
//             tmp /= 10;
//         }
//     }
// }

// void dfs(int pos)
// {
//     int sum_of_num = 0, sum_of_used_matches = 0;
//     for (int i = 0; i < pos - 1; i++)
//     {
//         sum_of_num += path[i];
//         sum_of_used_matches += matches_per_num[path[i]];
//     }
//     if (pos == 3)
//     {
//         if (matches_per_num[sum_of_num] == n - sum_of_used_matches)
//         {
//             // path.push_back(sum_of_num);
//             // res.push_back(path);
//             // path.pop_back();
//             ans++;
//         }
//         return;
//     }
//     for (int i = 0; i < 1000; i++)
//     {
//         if (matches_per_num[sum_of_num] > n - 2)
//             continue;
//         path.push_back(i);
//         dfs(pos + 1);
//         path.pop_back();
//     }
// }

// ==================================================================

/*
    递归中循环过多
*/

// int main()
// {
//     cin >> n;
//     if (n <= 10)
//     {
//         printf("0\n");
//         return 0;
//     }
//     n -= 4;
//     init_matches();
//     dfs(1);

//     cout << ans << '\n';

//     // for (const auto &arr : res)
//     // {
//     //     for (const int &e : arr)
//     //         cout << e << " ";
//     //     cout << '\n';
//     // }

//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int matches_per_num[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
// vector<int> path;
// vector<vector<int>> res;
// int ans = 0;
// int n;

// int get_matches_of_num(int num)
// {
//     if (num < 10)
//         return matches_per_num[num];
//     int ans = 0;
//     while (num)
//     {
//         ans += matches_per_num[num % 10];
//         num /= 10;
//     }
//     return ans;
// }

// void dfs(int pos)
// {
//     int sum_of_num = 0, sum_of_used_matches = 0;
//     for (int i = 0; i < pos - 1; i++)
//     {
//         sum_of_num += path[i];
//         sum_of_used_matches += get_matches_of_num(path[i]);
//     }
//     if (pos == 3)
//     {
//         if (get_matches_of_num(sum_of_num) == n - sum_of_used_matches)
//         {
//             path.push_back(sum_of_num);
//             res.push_back(path);
//             path.pop_back();
//             ans++;
//         }
//         return;
//     }
//     for (int i = 0; i < 1000; i++)
//     {
//         path.push_back(i);
//         dfs(pos + 1);
//         path.pop_back();
//     }
// }

// int main()
// {
//     cin >> n;
//     if (n <= 10)
//     {
//         printf("0\n");
//         return 0;
//     }
//     n -= 4;

//     dfs(1);

//     cout << ans << '\n';

//     for (const auto &arr : res)
//     {
//         for (const int &e : arr)
//             cout << e << " ";
//         cout << '\n';
//     }

//     return 0;
// }