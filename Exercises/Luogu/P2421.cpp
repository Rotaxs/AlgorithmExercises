#include <iostream>
#include <algorithm>

using namespace std;

int n, c[20], p[20], l[20];

int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

bool check(int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int a = p[i] - p[j];
            int b = c[j] - c[i];
            int mod = m;
            int x, y;
            int d = exgcd(a, mod, x, y);

            if (b % d == 0)
            {
                int t = abs(mod / d);
                x = (x * (b / d) % t + t) % t;
                if (x <= min(l[i], l[j]))
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    cin >> n;
    int max_c = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i] >> p[i] >> l[i];
        max_c = max(max_c, c[i]);
    }
    for (int m = max_c; m <= 1000000; m++)
    {
        if (check(m))
        {
            cout << m << endl;
            break;
        }
    }

    return 0;
}