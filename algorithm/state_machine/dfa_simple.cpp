#include <iostream>
using namespace std;

/**
 * 实现一个简单的有限自动状态机
 * 状态列表 {0, 1}
 * 输入字母表 {a, b}
 * 状态转移函数
 *  f(0, a) = 1
 *  f(0, b) = 0
 *  f(1, a) = 0
 *  f(1, b) = 0
 * 初始状态 q = 0
 * 可接受状态集合 {1}
 */

#define STATUS_COUNT 2
#define ALPHA_COUNT 2

int delta[STATUS_COUNT][ALPHA_COUNT] = {
    {1, 0},
    {0, 0}};

int func(char ch)
{
    if (ch == 'a')
        return 0;
    else if (ch == 'b')
        return 1;
    return -1;
}

int main()
{
    char str[] = "abbabbbaa";
    char *p;
    int s = 0; // 起始状态
    int q = s; // 转移状态
    // 启动状态机
    for (p = str; *p != '\0'; p++)
    {
        // *p 表示当前输入
        q = delta[q][func(*p)];
    }
    if (q == 1)
        cout << "accepted" << '\n';
    else
        cout << "unaccepted" << '\n';
    return 0;
}