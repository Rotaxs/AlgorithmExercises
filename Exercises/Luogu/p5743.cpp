#include <iostream>
using namespace std;

int main()
{
    int n, res = 1;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        res = (res + 1) * 2;
    }
    cout << res << '\n';
    return 0;
}