#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
int len;
int p = 0;

bool is_alpha(char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }
bool is_digit(char c) { return c >= '0' && c <= '9'; }

string dfs()
{
    string ret = "";

    // 当 p 未越界，且没有遇到当前层的结束符 ']' 时，持续解析
    while (p < len && s[p] != ']')
    {
        if (is_alpha(s[p]))
        {
            ret += s[p];
            p++; // 普通字母直接拼接，指针后移
        }
        else if (s[p] == '[')
        {
            p++; // 跳过左括号 '['

            // 题目格式为 [n<string>]，进入括号后必然先是一串数字，立刻读取它
            int cnt = 0;
            while (p < len && is_digit(s[p]))
            {
                cnt = cnt * 10 + s[p] - '0';
                p++;
            }
            // 括号里剩下的字母或嵌套的括号，交给下一层 dfs 处理
            string part = dfs();
            // 将下一层处理完的子串，重复 cnt 次加入到当前结果中
            while (cnt--)
            {
                ret += part;
            }
            // 此时 dfs() 返回，说明必定碰到了 ']'，我们需要跳过这个右括号
            if (p < len && s[p] == ']')
            {
                p++;
            }
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    len = s.length();

    string ans = dfs();
    cout << ans << '\n';

    return 0;
}