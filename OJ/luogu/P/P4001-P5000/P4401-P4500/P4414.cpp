#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a, b, c;
string order;

void sort_three(int &a, int &b, int &c)
{
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
}

int main()
{
    cin >> a >> b >> c;
    cin >> order;

    sort_three(a, b, c);

    for (char &o : order)
    {
        if (o == 'A')
            cout << a << " ";
        if (o == 'B')
            cout << b << " ";
        if (o == 'C')
            cout << c << " ";
    }
    return 0;
}