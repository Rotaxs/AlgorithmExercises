#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010;
const int LEN = 250;
int ans[N][LEN];

void add(int a[], int b[], int c[])
{
    for (int i = 0; i < LEN; i++)
    {
        c[i] += a[i] + b[i];
        if (c[i] >= 10)
        {
            c[i + 1] = c[i] / 10;
            c[i] %= 10;
        }
    }
}

void print(int a[])
{
    int i;
    for (i = LEN - 1; i > 0; i--)
        if (a[i] != 0)
            break;
    for (; i >= 0; i--)
        cout << a[i];
}

int main()
{
    int n, m;
    cin >> m >> n;
    memset(ans, 0, sizeof(ans));
    ans[m][0] = 1;
    ans[m + 1][0] = 1;
    for (int i = m + 2; i <= n; i++)
        add(ans[i - 1], ans[i - 2], ans[i]);
    print(ans[n]);
    return 0;
}