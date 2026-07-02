#include <iostream>
using namespace std;

int year, month;

int main()
{
    cin >> year >> month;
    bool flag1 = year % 4 == 0 && year % 100 != 0;
    bool flag2 = year % 400 == 0;

    int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (flag1 || flag2)
        days_per_month[1] = 29;

    cout << days_per_month[month - 1] << endl;

    return 0;
}