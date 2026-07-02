#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string countOfAtoms(string formula)
    {
        int p = 0;
        string ans = "";
        map<string, int> ansm = f(formula, p);
        for (auto item : ansm)
        {
            ans += item.first;
            if (item.second != 1)
            {
                ans += itos(item.second);
            }
        }
        return ans;
    }

    string itos(int num)
    {
        string ret;
        while (num)
        {
            ret += (num % 10) + '0';
            num /= 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    map<string, int> f(string &formula, int &p)
    {
        string cur = "";
        map<string, int> res;
        while (p < formula.length() && formula[p] != ')')
        {
            if (is_upper(formula[p]))
            {
                if (cur.size())
                {
                    res[cur]++;
                    cur.clear();
                }
                cur += formula[p];
            }
            else if (is_lower(formula[p]))
            {
                cur += formula[p];
            }
            else if (is_digit(formula[p]))
            {
                int cnt = 0;
                // p 跳到下一个非数字字符
                while (p < formula.length() && is_digit(formula[p]))
                {
                    cnt = cnt * 10 + formula[p] - '0';
                    p++;
                }
                // p 回到下一个非数字字符的第一位的前面
                p--;
                res[cur] += cnt;
                cur.clear();
            }
            else
            {
                if (cur.size())
                {
                    res[cur]++;
                    cur.clear();
                }
                p++;
                map<string, int> ret = f(formula, p);
                int cnt = 0;
                if (p + 1 < formula.length() && is_digit(formula[p + 1]))
                {
                    p++;
                    while (p < formula.length() && is_digit(formula[p]))
                    {
                        cnt = cnt * 10 + formula[p] - '0';
                        p++;
                    }
                    p--;
                }
                else
                {
                    cnt = 1;
                }
                for (auto item : ret)
                {
                    res[item.first] += item.second * cnt;
                }
            }
            p++;
        }
        if (cur.size())
        {
            res[cur]++;
        }
        return res;
    }

    bool is_upper(char c)
    {
        return c >= 'A' && c <= 'Z';
    }

    bool is_lower(char c)
    {
        return c >= 'a' && c <= 'z';
    }

    bool is_digit(char c)
    {
        return c >= '0' && c <= '9';
    }
};

// ========= Debug ==========

bool is_upper(char c)
{
    return c >= 'A' && c <= 'Z';
}

bool is_lower(char c)
{
    return c >= 'a' && c <= 'z';
}

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

map<string, int> f(string &formula, int &p)
{
    string cur = "";
    map<string, int> res;
    while (p < formula.length() && formula[p] != ')')
    {
        if (is_upper(formula[p]))
        {
            if (cur.size())
            {
                res[cur]++;
                cur.clear();
            }
            cur += formula[p];
        }
        else if (is_lower(formula[p]))
        {
            cur += formula[p];
        }
        else if (is_digit(formula[p]))
        {
            int cnt = 0;
            // p 跳到下一个非数字字符
            while (p < formula.length() && is_digit(formula[p]))
            {
                cnt = cnt * 10 + formula[p] - '0';
                p++;
            }
            // p 回到下一个非数字字符的第一位的前面
            p--;
            res[cur] += cnt;
            cur.clear();
        }
        else
        {
            if (cur.size())
            {
                res[cur]++;
                cur.clear();
            }
            p++;
            map<string, int> ret = f(formula, p);
            int cnt = 0;
            if (p + 1 < formula.length() && is_digit(formula[p + 1]))
            {
                p++;
                while (p < formula.length() && is_digit(formula[p]))
                {
                    cnt = cnt * 10 + formula[p] - '0';
                    p++;
                }
                p--;
            }
            else
            {
                cnt = 1;
            }
            for (auto item : ret)
            {
                res[item.first] += item.second * cnt;
            }
        }
        p++;
    }
    if (cur.size())
    {
        res[cur]++;
    }
    return res;
}

string countOfAtoms(string formula)
{
    int p = 0;
    string ans = "";
    map<string, int> ansm = f(formula, p);
    for (auto item : ansm)
    {
        ans += item.first;
        if (item.second != 1)
        {
            ans += itos(item.second);
        }
    }
    return ans;
}

string itos(int num)
{
    string ret;
    while (num)
    {
        ret += (num % 10) + '0';
        num /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    int p = 0;
    string s = "Mg(OH)2";
    cout << countOfAtoms(s) << endl;
    return 0;
}
