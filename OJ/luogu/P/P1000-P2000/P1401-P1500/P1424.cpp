#include <iostream>
using namespace std;

int x, n;

int main()
{
    cin >> x >> n;
    int work_days = 0;
    if (x <= 5)
    {
        if (x + n <= 5)
            work_days = n;
        else if (x + n <= 7)
            work_days = 5 - x + 1;
        else
        {
            int left_days_fir_week = 7 - x + 1; // 5
            int left_days = n - left_days_fir_week;
            if (left_days % 7 <= 5)
                work_days = left_days / 7 * 5 + left_days % 7 + 5 - x + 1;
            else
                work_days = left_days / 7 * 5 + 5 + (5 - x + 1);
        }
    }
    else
    {
        int left_days_fir_week = 7 - x + 1;
        if (n < left_days_fir_week)
            work_days = 0;
        else
        {
            int left_days = n - left_days_fir_week;
            if (left_days % 7 <= 5)
                work_days = left_days / 7 * 5 + left_days % 7;
            else
                work_days = left_days / 7 * 5 + 5;
        }
    }

    cout << work_days * 250 << endl;
}