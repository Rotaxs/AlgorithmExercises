#include <iostream>
using namespace std;

int main()
{
    int buget;
    int money = 0;
    int mom = 0;
    int X = 0;
    for (int i = 1; i <= 12; i++)
    {
        money += 300;
        cin >> buget;
        if (money < buget && X == 0)
        {
            X = -i;
        }
        money -= buget;
        if (money >= 100)
        {
            mom += money / 100 * 100;
            money %= 100;
        }
    }
    if (X == 0)
        cout << mom * 1.2 + money << '\n';
    else
        cout << X << '\n';
    return 0;
}