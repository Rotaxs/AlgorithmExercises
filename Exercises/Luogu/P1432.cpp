#include <iostream>
using namespace std;

double s;

int main()
{
    cin >> s;
    double sum = 0, a = 2, cnt = 0;
    while (s - sum > 1e-6)
    {
        sum += a;
        a *= 0.98;
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}