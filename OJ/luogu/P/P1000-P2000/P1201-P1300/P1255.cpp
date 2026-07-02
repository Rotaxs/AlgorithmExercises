#include <iostream>
using namespace std;

const int N = 5010;
const int LEN = 2000;
int solus[N][LEN];
int n;

void clear(int a[])
{
    for (int i = 0; i < LEN; i++)
        a[i] = 0;
}

void add(int a[], int b[], int c[])
{
    for (int i = 0; i < LEN; i++)
    {
        c[i] += a[i] + b[i];
        if (c[i] >= 10)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}

int main()
{
    cin >> n;
    solus[1][0] = 1;
    solus[2][0] = 2;
    for (int i = 3; i <= n; i++)
        add(solus[i - 1], solus[i - 2], solus[i]);
    int i;
    for (i = LEN - 1; i > 0; i--)
        if (solus[n][i] != 0)
            break;
    for (; i >= 0; i--)
        cout << solus[n][i];
    cout << '\n';
    return 0;
}