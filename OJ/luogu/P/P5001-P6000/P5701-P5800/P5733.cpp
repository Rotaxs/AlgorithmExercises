#include <iostream>
using namespace std;

int main()
{
    char str[100];
    cin >> str;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 'a' - 'A';
    }
    cout << str << '\n';
    return 0;
}