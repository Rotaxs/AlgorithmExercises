#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;
    int num, sum = 0;
    int max = 0, min = 10;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        sum += num;
        if (num > max)
            max = num;
        if (num < min)
            min = num;
    }
    sum -= max;
    sum -= min;
    double res = (double)sum / (n - 2);
    printf("%.2lf", res);

    return 0;
}