#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        int p = 0;
        return f(p, s);
    }
    string f(int &p, string &s)
    {
        string res = "";
        int cur = 0;
        while (p < s.length() && s[p] != ']')
        {
            // 如果遇到数字，可能有多位，将数组存储到 cur
            if (s[p] >= '0' && s[p] <= '9')
            {
                cur = cur * 10 + s[p] - '0';
            }
            else if (s[p] == '[')
            {
                p++;
                // 这里调用 f 会将 p 移动到下一个 ] 的位置
                string tmp = f(p, s);
                // 循环 cur 次，将 cur 后的 [] 内容复制 cur 遍到 res
                // 同时将 cur 清零
                while (cur--)
                {
                    res += tmp;
                }
                cur = 0;
            }
            // 遇到字母
            else
            {
                res += s[p];
            }
            p++;
        }

        return res;
    }
};
