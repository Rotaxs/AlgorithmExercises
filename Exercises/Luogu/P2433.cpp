#include <iostream>
#include <cmath>
#define pi 3.141593
using namespace std;

int option;

int main()
{
    cin >> option;
    switch (option)
    {
    case 1:
        cout << "I love Luogu!" << endl;
        break;
    case 2:
        cout << 6 << " " << 4 << endl;
        break;
    case 3:
        cout << 3 << "\n";
        cout << 12 << "\n";
        cout << 2 << "\n";
        break;
    case 4:
        printf("%.3f", 500.0 / 3.0);
        break;
    case 5:
        cout << 15 << "\n";
        break;
    case 6:
        cout << sqrt(6 * 6 + 9 * 9) << "\n";
        break;
    case 7:
        cout << 110 << "\n"
             << 90 << "\n"
             << 0 << "\n";
        break;
    case 8:
        cout << 2 * pi * 5 << "\n";
        cout << pi * 5 * 5 << "\n";
        cout << 4.0 / 3.0 * pi * 5 * 5 * 5 << "\n";
        break;
    case 9:
        cout << 22 << "\n";
        break;
    case 10:
        cout << 9 << "\n";
        break;
    case 11:
        cout << 100.0 / 3.0 << "\n";
        break;
    case 12:
        cout << 'M' - 'A' + 1 << "\n"
             << (char)('A' + 17) << "\n";
        break;
    case 13:
        cout << 16 << "\n";
        break;
    case 14:
        cout << 50 << "\n";
        break;
    }
    return 0;
}
