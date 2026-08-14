#include <iostream>
using namespace std;

int k;

bool check(int n)
{
    int a1, a2, a3, a4, a5;
    a1 = n / 10000;
    a2 = n % 10000 / 1000;
    a3 = n % 10000 % 1000 / 100;
    a4 = n % 10000 % 1000 % 100 / 10;
    a5 = n % 10000 % 1000 % 100 % 10;
    bool flag1 = ((100 * a1 + 10 * a2 + a3) % k) == 0;
    bool flag2 = ((100 * a2 + 10 * a3 + a4) % k) == 0;
    bool flag3 = ((100 * a3 + 10 * a4 + a5) % k) == 0;
    return flag1 && flag2 && flag3;
}

int main()
{
    cin >> k;
    bool found = false;
    for (int i = 10000; i <= 30000; i++)
    {
        if (check(i))
        {
            if (!found)
                found = true;
            cout << i << '\n';
        }
    }
    if (!found)
        cout << "No" << '\n';
    return 0;
}