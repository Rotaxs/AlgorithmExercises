#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 1004;

int a[LEN], b[LEN], c[LEN], d[LEN];

void clear(int a[])
{
    for (int i = 0; i < LEN; i++) a[i] = 0;
}

void read(int a[])
{
    string s; cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++) a[i] = s[len - 1 - i] - '0';
}

void print(int a[])
{
    int i;
    // i >= 1 当整个数组都是 0 时，输出 0
    for (i = LEN - 1; i >= 1; i--)
        if (a[i] != 0) break;
    for (; i >= 0; i--) cout << a[i];
    cout << '\n';
}

void add(int a[], int b[], int c[])
{
    clear(c);
    for (int i = 0; i < LEN - 1; i++)
    {
        c[i] += a[i] + b[i];
        if (c[i] >= 10)
        {
            c[i] -= 10;
            c[i + 1] += 1;
        }
    }
}

// a 一定要比 b 大
void sub(int a[], int b[], int c[])
{
    clear(c);
    for (int i = 0; i < LEN - 1; i++)
    {
        c[i] += a[i] - b[i];
        if (c[i] < 0)
        {
            c[i + 1]--;
            c[i] += 10;
        }
    }
}

void mul_short(int a[], int b, int c[])
{
    clear(c);
    for (int i = 0; i < LEN - 1; i++)
    {
        c[i] += a[i] * b;
        if (c[i] >= 10)
        {
            c[i + 1] += c[i] / 10;
            c[i] = c[i] % 10;
        }
    }
}

// c 的第 i 位由 a 的第 j 位和 b 的第 i-j 位相乘的个位和前一位的进位组成
// 123456 a[] ={6, 5, 4, 3, 2, 1}
void mul(int a[], int b[], int c[])
{
    clear(c);
    for (int i = 0; i < LEN - 1; i++)
    {
        for (int j = 0; j <= i; j++)
            c[i] += a[j] * b[i - j];
        if (c[i] >= 10)
        {
            c[i + 1] = c[i] / 10;
            c[i] = c[i] % 10;
        }
    }
}

bool can_div(int a[], int b[], int last_pos, int len)
{
    // a[last_pos + len - 1] 对应 b 的最高位
    // 如果 a[last_pos + len] 不等于 0，意味着 a 比 b至少多一位
    if (a[last_pos + len] != 0)
        return true;
    // 从高位开始比较
    for (int i = len - 1; i >= 0; i++)
    {
        if (a[last_pos + i] > b[i])
            return true;
        if (a[last_pos + i] < b[i])
            return false;
    }
    // 如果上面没有返回，说明每一位都相同
    return true;
}

void div(int a[], int b[], int c[], int d[])
{
    clear(c);
    clear(d);

    // 数字的位数
    int la, lb;
    for (la = LEN - 1; la > 0; la--)
    {
        if (a[la - 1] != 0)
            break;
    }
    for (lb = LEN - 1; lb > 0; lb--)
    {
        if (b[lb - 1] != 0)
            break;
    }
    if (lb == 0)
        return;

    // d 是余数数组，每次进行高精减时，直接操作 d，那么剩下的就是余数
    for (int i = 0; i < la; i++)
    {
        d[i] = a[i];
    }

    // 将 b 的最高位与 a 的最高位对齐，模拟竖式除法
    for (int i = la - lb; i >= 0; i--)
    {
        // 如果能减，就一直减
        while (can_div(d, b, i, lb))
        {
            for (int j = i; j < i + lb; j++)
            {
                d[j] -= b[j - i];
                if (d[j] < 0)
                {
                    d[j + 1]--;
                    d[j] += 10;
                }
            }
            // 每次减完，商增加 1
            c[i]++;
        }
    }
}

void copy(int src[], int dst[])
{
    for (int i = 0; i < LEN; i++)
    {
        dst[i] = src[i];
    }
}

int main()
{
    read(a);
    print(a);
    return 0;
}