#include <iostream>
using namespace std;

int a;

int main()
{
    cin >> a;
    int days = 1;
    while (a != 1)
    {
        a /= 2;
        days++;
    }
    cout << days << endl;
    return 0;
}