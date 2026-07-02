#include <iostream>
#include <cmath>
using namespace std;

int n;

int main()
{
    cin >> n;
    if (n == 0)
    {
        printf("0.00\n");
        return 0;
    }
    double a, tmp_a, b, tmp_b;
    tmp_a = a = (1 + sqrt(5)) / 2;
    tmp_b = b = (1 - sqrt(5)) / 2;
    double res = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        a *= tmp_a;
        b *= tmp_b;
    }
    res = (a - b) / sqrt(5);
    printf("%.2f\n", res);
    return 0;
}