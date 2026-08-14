#include <iostream>
using namespace std;

int m, t, s;

int main()
{
    cin >> m >> t >> s;
    if (t == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        int result = m - (s + t - 1) / t;
        if (result >= 0)
            cout << result << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}