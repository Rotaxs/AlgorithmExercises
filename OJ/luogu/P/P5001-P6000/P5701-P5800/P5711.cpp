#include <iostream>
using namespace std;

int year;

int main()
{
    cin >> year;
    bool flag1 = year % 4 == 0 && year % 100 != 0;
    bool flag2 = year % 400 == 0;
    if (flag1 || flag2)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}