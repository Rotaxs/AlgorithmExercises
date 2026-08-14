#include <iostream>
using namespace std;

int sum_nk = 0, sum_k = 0;
int cnt_k = 0;
int n, k;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
        {
            sum_k += i;
            cnt_k++;
        }
        else
            sum_nk += i;
    }
    printf("%.1f %.1f", (float)sum_k / cnt_k, (float)sum_nk / (n - cnt_k));
    return 0;
}