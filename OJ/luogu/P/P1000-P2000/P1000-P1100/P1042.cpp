#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const int N = 1e4 + 10;
string str;

void print_result(int x)
{
    int A = 0, B = 0;
    for (auto e : str)
    {
        if (e == 'W')
        {
            A++;
        }
        else if (e == 'L')
        {
            B++;
        }
        if ((A >= x || B >= x) && fabs(A - B) >= 2)
        {
            cout << A << ":" << B << endl;
            A = 0;
            B = 0;
        }
    }
    cout << A << ":" << B << endl;
}

int main()
{
    char ch;
    while (cin >> ch)
    {
        if (ch == 'E')
            break;
        str += ch;
    }
    print_result(11);
    cout << endl;
    print_result(21);
}