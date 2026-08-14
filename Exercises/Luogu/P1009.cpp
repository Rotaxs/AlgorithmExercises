#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 1000;

int a[LEN], b[LEN], c[LEN];

void clear(int a[])
{
    for (int i = 0; i < LEN; i++)
        a[i] = 0;
}

void read(int a[])
{
    char s[LEN + 1];
    scanf("%s", s);

    int len = strlen(s);

    for (int i = 0; i < len; i++)
        a[i] = s[len - 1 - i] - '0';
}

void print(int a[])
{
    int i;
    for (i = LEN - 1; i > 0; i--)
    {
        if (a[i] != 0)
            break;
    }
    for (; i >= 0; i--)
    {
        printf("%d", a[i]);
    }
    putchar('\n');
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

void mul_short(int a[], int b, int c[])
{
    clear(c);

    for (int i = 0; i < LEN; i++)
    {
        c[i] += a[i] * b;
        if (c[i] >= 10)
        {
            c[i + 1] = c[i] / 10;
            c[i] = c[i] % 10;
        }
    }
}

void copy(int src[], int dst[])
{
    for (int i = 0; i < LEN; i++)
        dst[i] = src[i];
}

void factorial(int n, int c[])
{
    clear(c);

    c[0] = 1;

    if (n == 1)
        return;

    int tmp[LEN];
    for (int i = 2; i <= n; i++)
    {
        copy(c, tmp);
        mul_short(tmp, i, c);
    }
}

int main()
{
    int n;
    cin >> n;
    int res[LEN];
    clear(res);
    for (int i = 1; i <= n; i++)
    {
        factorial(i, a);
        copy(res, b);
        add(a, b, res);
    }
    print(res);
    return 0;
}