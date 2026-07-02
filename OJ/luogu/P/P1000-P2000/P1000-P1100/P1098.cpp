#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p1, p2, p3;
string str;

int main()
{
    cin >> p1 >> p2 >> p3;
    cin >> str;

    int i = 0;
    char l, m, r, j, jc;
    while (str[i])
    {
        if (i == 0)
        {
            cout << str[i];
            i++;
            continue;
        }
        if (i == str.length() - 1)
        {
            cout << str[i];
            break;
        }
        l = str[i - 1];
        m = str[i];
        r = str[i + 1];
        if (m == '-' && l < r && ((l >= '0' && r <= '9') || (l >= 'a' && r <= 'z')))
        {
            for (p3 == 1 ? j = l + 1 : j = r - 1; p3 == 1 ? j < r : j > l; p3 == 1 ? j++ : j--)
            {
                jc = j;
                if (p1 == 2 && jc >= 'a')
                    jc -= 'a' - 'A';
                else if (p1 == 3)
                    jc = '*';
                for (int c = 0; c < p2; c++)
                    cout << jc;
            }
        }
        else
            cout << m;
        i++;
    }
    return 0;
}