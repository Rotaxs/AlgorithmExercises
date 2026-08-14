#include <iostream>
#include <cstring>
using namespace std;

const int N = 10000;

int a[N], b[N];

void read(int a[])
{
    char num[N + 1];
    scanf("%s", num);
    int len = strlen(num);

    for (int i = 0; i < len; i++)
    {
        a[len - i - 1] = num[i] - '0';
    }
}

void clear(int a[])
{
    for (int i = 0; i < N; i++)
        a[i] = 0;
}

void print(int a[])
{
    int i = N - 1;
    for (; i >= 1; i--)
        if (a[i] != 0)
            break;
    for (; i >= 0; i--)
        putchar(a[i] + '0');
    putchar('\n');
}

void mul_short(int a[], int b)
{
    int carry = 0; // 用一个独立的变量存进位
    for (int i = 0; i < N; i++)
    {
        // 关键：先计算当前位乘法结果，加上上一位的进位
        long long cur = (long long)a[i] * b + carry;

        a[i] = cur % 10;  // 更新当前位
        carry = cur / 10; // 更新进位，留给下一轮 i+1 使用
    }
}

void copy(int a[], int b[])
{
    for (int i = 0; i < N; i++)
    {
        b[i] = a[i];
    }
}

void factorial(int n, int a[])
{
    clear(a);

    a[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        mul_short(a, i);
    }
}

int get_highest_bit(int a[])
{
    int i = N - 1;
    for (; i >= 0; i--)
        if (a[i] != 0)
            break;
    return i;
}

int main()
{
    // read(a);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, aa, ans = 0;
    cin >> t;
    while (t--)
    {
        cin >> n >> aa;
        ans = 0;
        clear(a);
        factorial(n, a);
        for (int i = 0; i <= get_highest_bit(a); i++)
        {
            if (a[i] == aa)
                ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
