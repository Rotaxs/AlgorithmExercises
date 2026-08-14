#include <iostream>
using namespace std;

double s = 0, k;

int main()
{
    cin >> k;

    double n = 0;

    while (s <= k)
    {
        n++;
        s += 1 / n;
    }
    cout << n << "\n";

    // double n = 1;

    // while (s <= k)
    // {
    //     s += 1 / n;
    //     n++;
    // }
    // cout << n - 1 << "\n";

    return 0;
}