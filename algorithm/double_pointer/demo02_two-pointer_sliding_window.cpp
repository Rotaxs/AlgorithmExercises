/**
 * 给定一个字符串 S，一个字符串 T，要求在 S 中找出包含 T 所有字母的最小子串
 */

// =================================================================

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

bool has_zero(unordered_map<char, int> map1)
{
    for (auto e : map1)
    {
        if (e.second == 0)
            return true;
    }
    return true;
}

int main()
{
    string s = "ACDODEABCDDCBAO", t = "ABC";
    unordered_map<char, int> window, target;
    for (char ch : t)
        target[ch]++;

    int min_len = INT_MAX;
    int windowCnt = 0;
    int r = 0, l = 0;

    for (r = 0; r < s.length(); r++)
    {
        if (target.count(s[r]))
        {
            window[s[r]]++;
            if (window[s[r]] == target[s[r]])
                windowCnt++;
        }
        while (windowCnt == target.size())
        {

            if (target.count(s[l]))
            {
                window[s[l]]--;
                if (window[s[l]] != target[s[l]])
                    windowCnt--;
            }
            l++;
        }
        min_len = min(min_len, r - l + 1);
    }
    cout << min_len << endl;
    return 0;
}

// =================================================================

// #include <iostream>
// #include <string>
// #include <ctype.h>
// #include <unordered_map>
// using namespace std;

// int main()
// {
//     string s = "ADOBECODEBANC", t = "ABC";
//     unordered_map<char, int> window;
//     unordered_map<char, int> target;
//     for (char &c : t)
//         target[c]++;
//     int l = 0, r = 0; =
//     int windowCnt = 0; // 用windowCnt维护window中满足要求的字符种数
//     int start = 0, minlen = INT_MAX;
//     while (r < s.length())
//     {
//         // 右指针移动
//         if (target.count(s[r]))
//         {
//             window[s[r]]++; // 如果target中有s[r]这个字符，那么滑动窗口中也添加一个该字符
//             if (window[s[r]] == target[s[r]])
//                 windowCnt++;
//         }
//         r++;
//         // 左指针满足滑动窗口中包含 T 中所有字符时移动
//         while (windowCnt == target.size())
//         {
//             // 该窗口符合条件，判断其长度是否为最小
//             if (r - l < minlen)
//             {
//                 start = l;
//                 minlen = r - l;
//             }

//             // 如果是 T 中有的字符，则将对应的值减少
//             if (target.count(s[l]))
//             {
//                 // 滑动窗口左指针右移，字符减少
//                 window[s[l]]--;
//                 // 如果删除的元素是 T 中有的字符，那么窗口中的有效字符减少，并结束循环
//                 if (window[s[l]] < target[s[l]])
//                     windowCnt--;
//             }
//             l++;
//         }
//     }
//     string res = minlen == INT_MAX ? "" : s.substr(start, minlen);
//     cout << res << endl;

//     return 0;
// }
