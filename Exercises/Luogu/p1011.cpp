#include <iostream>
using namespace std;

int up_a[25], up_x[25];
int sum_a[25], sum_x[25];

int main()
{
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    up_a[1] = 1, up_x[1] = 0;
    up_a[2] = 0, up_x[2] = 1;
    sum_a[1] = 1, sum_x[1] = 0;
    sum_a[2] = 1, sum_x[2] = 0;

    for (int i = 3; i < n; i++)
    {
        up_a[i] = up_a[i - 1] + up_a[i - 2];
        up_x[i] = up_x[i - 1] + up_x[i - 2];

        sum_a[i] = sum_a[i - 1] + up_a[i] - up_a[i - 1];
        sum_x[i] = sum_x[i - 1] + up_x[i] - up_x[i - 1];
    }

    int x_value = 0;
    if (sum_x[n - 1] != 0)
    {
        x_value = (m - sum_a[n - 1] * a) / sum_x[n - 1];
    }

    cout << sum_a[x] * a + sum_x[x] * x_value << endl;

    return 0;
}