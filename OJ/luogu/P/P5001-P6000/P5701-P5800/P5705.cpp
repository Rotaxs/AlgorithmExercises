#include <iostream>
#include <string>
using namespace std;

int main()
{
    string ch;
    cin >> ch;
    for (int i = 4; i >= 0; i--)
    {
        cout << ch[i];
    }
    cout << endl;
}
