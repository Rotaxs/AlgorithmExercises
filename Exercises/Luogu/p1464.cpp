#include <iostream>
using namespace std;

typedef long long LL;
LL ans[25][25][25];

LL w(LL a, LL b, LL c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    if (a < b && b < c)
    {
        if (!(ans[a][b][c - 1]))
            ans[a][b][c - 1] = w(a, b, c - 1);
        if (!(ans[a][b - 1][c - 1]))
            ans[a][b - 1][c - 1] = w(a, b - 1, c - 1);
        if (!(ans[a][b - 1][c]))
            ans[a][b - 1][c] = w(a, b - 1, c);
        ans[a][b][c] = ans[a][b][c - 1] + ans[a][b - 1][c - 1] - ans[a][b - 1][c];
    }
    else
    {
        if (!ans[a - 1][b][c])
            ans[a - 1][b][c] = w(a - 1, b, c);
        if (!ans[a - 1][b - 1][c])
            ans[a - 1][b - 1][c] = w(a - 1, b - 1, c);
        if (!ans[a - 1][b][c - 1])
            ans[a - 1][b][c - 1] = w(a - 1, b, c - 1);
        if (!ans[a - 1][b - 1][c - 1])
            ans[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
        ans[a][b][c] = ans[a - 1][b][c] + ans[a - 1][b - 1][c] + ans[a - 1][b][c - 1] - ans[a - 1][b - 1][c - 1];
    }

    return ans[a][b][c];
}

int main()
{
    LL a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a == -1 && b == -1 && c == -1)
            break;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
    }
    return 0;
}