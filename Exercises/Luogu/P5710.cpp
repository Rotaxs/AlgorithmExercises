#include <iostream>
using namespace std;

int x;

int main()
{
    cin >> x;
    bool flag1 = x % 2 == 0;
    bool flag2 = x > 4 && x <= 12;

    if (flag1 && flag2)
        cout << 1;
    else
        cout << 0;
    cout << " ";

    if (flag1 || flag2)
        cout << 1;
    else
        cout << 0;
    cout << " ";

    if ((flag1 && !flag2) || (!flag1 && flag2)) // flag1 != flag2 妙！
        cout << 1;
    else
        cout << 0;
    cout << " ";

    if (!flag1 && !flag2)
        cout << 1;
    else
        cout << 0;

    return 0;
}