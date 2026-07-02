/**
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 异位词指由相同字母重排列形成的字符串（包括相同的字符串）。
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int N = 1e5 + 1;

char s[N], p[N];

map<char, int> get_map(char *target, int size)
{
    map<char, int> ret;
    for (int i = 0; i < size; i++)
    {
        ret[target[i]]++;
    }
    return ret;
}

void input_string(char *str, int &size)
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        str[size] = ch;
        size++;
    }
}

int main()
{
    int size_s = 0, size_p = 0;
    input_string(s, size_s);
    input_string(p, size_p);

    if (size_s < size_p)
        return 0;

    map<char, int> p_map = get_map(p, size_p);
    map<char, int> window = get_map(s, size_p);

    vector<int> answers;
    int l = 0, r = size_p - 1;

    if (p_map == window)
        answers.push_back(l);

    while (r < size_s - 1)
    {
        if (window == p_map)
            answers.push_back(l);

        int char_out = s[l];
        int char_in = s[r + 1];
        if (--window[char_out] == 0)
            window.erase(char_out);
        window[char_in]++;

        l++;
        r++;
    }
    for (int &e : answers)
        cout << e << " ";
    cout << endl;

    return 0;
}
