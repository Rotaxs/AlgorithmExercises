#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 4010;

int a[LEN], b[LEN], c[LEN];

void clear(int a[])
{
    for (int i = 0; i < LEN; i++)
        a[i] = 0;
}

void read(int a[])
{
    char s[LEN];
    cin >> s;

    // cout << "s = " << s << endl;

    int len = strlen(s);

    // cout << "len = " << len << endl;

    for (int i = 0; s[i] != '\0'; i++)
    {
        a[i] = s[len - 1 - i] - '0';
        // cout << "a[" << i << "] = " << a[i] << endl;
    }
}

void print(int a[])
{
    int i;
    for (i = LEN - 1; i >= 1; i--)
    {
        if (a[i] != 0)
            break;
    }
    for (; i >= 0; i--)
        cout << a[i];
    cout << "\n";
}

void mul(int a[], int b[], int c[])
{
    clear(c);

    for (int i = 0; i < LEN; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            c[i] += a[j] * b[i - j];
        }
        if (c[i] >= 10)
        {
            c[i + 1] = c[i] / 10;
            c[i] = c[i] % 10;
        }
    }
}

int main()
{
    read(a);
    read(b);
    mul(a, b, c);
    print(c);
    return 0;
}