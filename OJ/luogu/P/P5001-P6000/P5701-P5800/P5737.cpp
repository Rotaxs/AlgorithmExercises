#include <iostream>
using namespace std;

const int N = 2000;
int years[N];

bool is_leap(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 4 == 0 && year % 100 != 0)
        return true;
    return false;
}

int main()
{
    int x, y;
    int cnt = 0;
    cin >> x >> y;

    for (int i = x; i <= y; i++)
    {
        if (is_leap(i))
            years[cnt++] = i;
    }
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++)
        cout << years[i] << ' ';
    cout << '\n';
    return 0;
}