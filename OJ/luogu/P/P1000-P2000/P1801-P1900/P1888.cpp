#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;

int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}

int main()
{
    cin >> a >> b >> c;

    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);

    int factor = gcd(a, c);
    cout << a / factor << "/" << c / factor << endl;

    return 0;
}