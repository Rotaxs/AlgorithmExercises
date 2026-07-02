#include <iostream>
using namespace std;

void decimal_to_x(int n, int x)
{
    if (n == 0)
        return;
    decimal_to_x(n / x, x);
    if (n % x < 10)
        printf("%d", n % x);
    else
        printf("%c", n % x + 'A' - 10);
}

int main()
{
    int n, x;
    cin >> n >> x;
    decimal_to_x(n, x);
    return 0;
}