#include <iostream>
using namespace std;

int x;

int main()
{
    cin >> x;
    if (x == 0 || x == 1)
        cout << "Today, I ate " << x << " apple." << endl;
    else
        cout << "Today, I ate " << x << " apples." << endl;
    return 0;
}