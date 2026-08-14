// 2025/12/4 重写

#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

string num_to_string(const string &num)
{
    int len = num.length();
    string ret(len, '0');
    for (int i = 0; i < len; i++)
    {
        ret[i] = num[len - i - 1];
    }
    return ret;
}

string string_to_num(const string &str)
{
    int len = str.length();
    if (str[len - 1] == '0')
        len--;
    string ret(len, '0');
    for (int i = 0; i < len; i++)
    {
        ret[i] = str[len - i - 1];
    }
    return ret;
}

pair<char, char> half_adder(char a, char b)
{
    a -= '0';
    b -= '0';
    pair<char, char> ret;
    if (a + b <= 9)
    {
        ret.first = a + b + '0';
        ret.second = '0';
    }
    else
    {
        ret.first = a + b - 10 + '0';
        ret.second = '1';
    }
    return ret;
}

pair<char, char> full_adder(char a, char b, char c)
{
    pair<char, char> ret;
    pair<char, char> o1 = half_adder(a, b);
    // o2 的本位就是真正的本位，o2的进位和o1的进位之和就是真正的进位
    pair<char, char> o2 = half_adder(o1.first, c);
    ret.first = o2.first;
    ret.second = o1.second + o2.second - '0';
    return ret;
}

string adder(string num1, string num2)
{
    num1 = num_to_string(num1);
    num2 = num_to_string(num2);
    if (num1.length() < num2.length())
        swap(num1, num2);
    int len_l = num1.length(), len_s = num2.length();
    string ret(len_l + 1, '0');
    pair<char, char> fa, ha;
    for (int i = 0; i < len_s; i++)
    {
        fa = full_adder(num1[i], num2[i], ret[i]);
        ret[i] = fa.first;
        ret[i + 1] = fa.second;
    }
    for (int i = len_s; i < len_l; i++)
    {
        ha = half_adder(num1[i], ret[i]);
        ret[i] = ha.first;
        ret[i + 1] = ha.second;
    }
    ret = string_to_num(ret);
    return ret;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << adder(a, b) << endl;

    return 0;
}

// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// struct Out
// {
//     int s;
//     int c;
// };

// Out half_add(int a, int b)
// {
//     int sum = a + b;
//     return {sum % 10, sum / 10}; // 简化逻辑
// }

// Out full_add(int a, int b, int c)
// {
//     int sum = a + b + c;
//     return {sum % 10, sum / 10};
// }

// string removeLeadingZeros(string s)
// {
//     int nonZero = 0;
//     while (nonZero < s.length() - 1 && s[nonZero] == '0')
//     {
//         nonZero++;
//     }
//     return s.substr(nonZero);
// }

// string n_pos_add(string num1, string num2)
// {
//     // 处理前导零
//     num1 = removeLeadingZeros(num1);
//     num2 = removeLeadingZeros(num2);

//     // 特殊情况处理
//     if (num1 == "0")
//         return num2;
//     if (num2 == "0")
//         return num1;

//     if (num2.length() > num1.length())
//     {
//         swap(num1, num2);
//     }

//     int size1 = num1.length();
//     int size2 = num2.length();

//     string ans = "";
//     int carry = 0;

//     // 从最低位开始相加
//     for (int i = 0; i < size2; i++)
//     {
//         int digit1 = num1[size1 - 1 - i] - '0';
//         int digit2 = num2[size2 - 1 - i] - '0';
//         Out out = full_add(digit1, digit2, carry);
//         ans += (out.s + '0'); // 关键：数字转字符
//         carry = out.c;
//     }

//     // 处理剩余位
//     for (int i = size2; i < size1; i++)
//     {
//         int digit1 = num1[size1 - 1 - i] - '0';
//         Out out = half_add(digit1, carry);
//         ans += (out.s + '0'); // 关键：数字转字符
//         carry = out.c;
//     }

//     if (carry != 0)
//     {
//         ans += (carry + '0'); // 关键：数字转字符
//     }

//     // 反转结果
//     reverse(ans.begin(), ans.end());
//     return ans;
// }

// int main()
// {
//     string num1, num2;
//     // 【关键修复】分两行读取输入
//     cin >> num1;
//     cin >> num2;

//     cout << n_pos_add(num1, num2) << endl;
//     return 0;
// }
