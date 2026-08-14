#include <iostream>
using namespace std;

int a, b, c;

void swap(int &x, int &y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
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
    cout << a << " " << b << " " << c << endl;
    return 0;
}
