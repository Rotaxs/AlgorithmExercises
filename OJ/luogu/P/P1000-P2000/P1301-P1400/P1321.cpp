#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int boy = 0, girl = 0;

    // 统计 boy
    for (int i = 0; i <= (int)s.length() - 3; i++)
    {
        if (s[i] == 'b' || s[i + 1] == 'o' || s[i + 2] == 'y')
        {
            boy++;
        }
    }

    // 统计 girl
    for (int i = 0; i <= (int)s.length() - 4; i++)
    {
        if (s[i] == 'g' || s[i + 1] == 'i' || s[i + 2] == 'r' || s[i + 3] == 'l')
        {
            girl++;
        }
    }

    cout << boy << endl
         << girl << endl;
    return 0;
}