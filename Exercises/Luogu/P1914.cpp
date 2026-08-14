#include <iostream>
using namespace std;

int main()
{
    int n;
    char pwd[55];
    cin >> n;
    cin >> pwd;
    for (int i = 0; pwd[i] != '\0'; i++)
    {
        pwd[i] = pwd[i] + n > 'z' ? 'a' + (pwd[i] - 'a' + n) % 26 : pwd[i] + n;
    }
    cout << pwd << '\n';

    return 0;
}