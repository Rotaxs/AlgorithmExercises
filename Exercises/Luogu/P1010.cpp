#include <iostream>
using namespace std;

void div(int x)
{
    for (int i = 14; i >= 0; i--)
    {
        if ((x >> i) & 1)
        {
            if (i == 0)
                cout << "2(0)";
            else if (i == 1)
            {
                cout << "2";
            }
            else
            {
                cout << "2(";
                div(i);
                cout << ")";
            }
            if (((1 << i) - 1) & x)
                cout << "+";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    div(n);
    return 0;
}