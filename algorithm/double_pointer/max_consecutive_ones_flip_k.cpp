/**
 * 给定一个 N 位的二进制数 S，最多进行 K 次翻转，一次翻转操作定义如下
 *  1. 选择 S 的任意一个连续子串
 *  2. 将子串中的所有字符进行反转
 * 计算在不超过 K 次翻转后，序列 S 中能够获得的最长的 1 的长度
 *
 * 输入：
 *  第一行包含两个数 N，K
 *  第二行是一个长度为 N 的字符串 S
 *
 * 输出：
 *  输出一个整数表示不超过 K 次翻转操作后可以获得的最长的 1 的长度
 *
 * 1 <= N, k <= 1e5
 */

// 2025/12/2 重做
// =========================================================================

#include <iostream>
#include <string>
using namespace std;

/*
    分析：每次操作可以选择任意长度的子串进行翻转，而要想 1 的长度最大，那么可以考虑选择一个最长子串，要求其中 0 的组数不超过 k
    使用滑动窗口，当窗口中的 0 的组数超过 k 时，左移左指针直到窗口中 0 的组数小于等于 k
    求 0 的组数：
        1. 右指针右移的过程中，如果当前位是 1，下一位是 0，则 0 的组数加一
        2. 左指针左移的过程中，如果当前位是 0，下一位是 1，则 0 的组数减一
*/

int n, k;
string S;

int main()
{
    cin >> n >> k;
    cin >> S;
    int zeroGroups = 0;
    int max_len = 0;
    int r = 0, l = 0;

    for (r = 0; r < S.length(); r++)
    {
        if (S[r] == '0')
        {
            if (r == 0 || S[r - 1] == '1')
            {
                zeroGroups++;
            }
        }
        while (zeroGroups > k)
        {
            if (S[l] == '0' && S[l + 1] == '1')
            {
                zeroGroups--;
            }
            l++;
        }
        max_len = max(max_len, r - l + 1);
    }
    cout << max_len << endl;
    return 0;
}

// =========================================================================

// #include <iostream>
// #include <string>
// using namespace std;

// /*
//     想要获得最长的 1，显然我们只能翻转 0
//     在一个子串中，连续的 0 的组数不超过 K，那么该子串就能全部变为 1
//     因此，该问题可以等价于找到最长的连续子串，其中 0 的组数不超过 K
// */

// const int N = 1e5 + 1;

// int n, k;
// string S;

// int main()
// {
//     cin >> n >> k;
//     cin >> S;

//     int l = 0, r = 0;
//     int maxlen = 0;

//     int zeroGroups = 0;

//     for (r = 0; r < S.length(); r++)
//     {
//         if (S[r] == '0')
//         {
//             if (r == 0 || S[r - 1] == '1')
//                 zeroGroups++;
//         }
//         while (zeroGroups > k)
//         {
//             if (S[l] == '0')
//             {
//                 if (S[l + 1] == '1' || l == r)
//                     zeroGroups--;
//             }
//             l++;
//         }
//         maxlen = max(maxlen, r - l + 1);
//     }
//     cout << maxlen << endl;

//     return 0;
// }