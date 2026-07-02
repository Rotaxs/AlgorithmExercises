#include <iostream>
using namespace std;

double a, b, c, d;

double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

double f_d(double x)
{
    return 3 * a * x * x + 2 * b * x + c;
}

double bi_search(double start, double end)
{
    double l = start + 1, r = end - 1;
    double m;
    for (int i = 0; i < 10000; i++)
    {
        m = (l + r) / 2;
        if (f(m) * f(l) <= 0)
            r = m;
        else
            l = m;
    }
    return m;
}

int main()
{
    cin >> a >> b >> c >> d;

    double l = -101, r = 101;
    for (int i = 0; i < 1000; i++)
    {
        r = r - f(r) / f_d(r);
        l = l - f(l) / f_d(l);
    }
    double m = bi_search(l, r);
    // cout << l << " " << m << " " << r << endl;
    printf("%.2lf %.2lf %.2lf", l, m, r);
    return 0;
}