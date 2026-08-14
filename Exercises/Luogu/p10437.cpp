// 下面的算法对于乘方的运算顺序处理错误
// 比如 2 ^ 2 ^ 3 应为 2 ^ (2 ^ 3) = 256
// 而下面的算法是 (2 ^ 2) ^ 3 = 64

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string s;
int where = 0;

void push(vector<int> &nums, vector<char> &ops, int cur, char op)
{
    int pre;
    if (ops.size())
    {
        switch (ops.back())
        {
        case '+':
        case '-':
            nums.push_back(cur);
            ops.push_back(op);
            break;
        case '*':
            pre = nums.back();
            nums.pop_back();
            ops.pop_back();
            nums.push_back(pre * cur);
            ops.push_back(op);
            break;
        case '/':
            pre = nums.back();
            nums.pop_back();
            ops.pop_back();
            nums.push_back(pre / cur);
            ops.push_back(op);
            break;
        case '^':
            pre = nums.back();
            nums.pop_back();
            ops.pop_back();
            nums.push_back(pow(pre, cur));
            ops.push_back(op);
            break;
        }
    }
    else
    {
        nums.push_back(cur);
        ops.push_back(op);
    }
}

int calc(vector<int> &nums, vector<char> &ops)
{
    if (nums.empty())
        return 0;
    int res = nums[0];
    for (int i = 1; i < (int)nums.size(); i++)
        res = ops[i - 1] == '+' ? res + nums[i] : res - nums[i];
    return res;
}

int solve(int p)
{
    int tmp = 0;
    int cur = 0;
    vector<int> nums; // 数字栈
    vector<char> ops; // 符号栈

    while (p < s.length() && s[p] != ')')
    {
        if (s[p] == '(')
        {
            tmp = solve(p + 1);
            // where 是 ) 的下标，在当前循环结束后会到下一个位置
            p = where;
        }
        // 处理多位数字
        else if (s[p] >= '0' && s[p] <= '9')
        {
            cur = cur * 10 + s[p] - '0';
        }
        else
        {
            // 将符号和当前数字入栈
            if (cur == 0)
                push(nums, ops, tmp, s[p]);
            else
                push(nums, ops, cur, s[p]);
            cur = 0; // 清空 cur
        }
        p++;
    }
    // 由于 p 到达结尾时循环就结束了，因此需要在这里将最后一个数字添加到栈
    // 同时 ops 中最后用 + 占位
    if (cur == 0)
        push(nums, ops, tmp, '+');
    else
        push(nums, ops, cur, '+');
    // p 此时为 ) 的下标或者已经到达 s 的长度
    where = p;
    // 通过提供的栈（数字栈和符号栈）计算出当前区间（一对括号内或是整个区间）的值
    return calc(nums, ops);
}

int main()
{
    cin >> s;
    cout << solve(0) << '\n';

    return 0;
}