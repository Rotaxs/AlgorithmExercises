#include <iostream>
using namespace std;

int n;

void decimal_to_binary(int n)
{
    if (n == 0)
        return;
    decimal_to_binary(n / 2);
    printf("%d", n % 2);
}

int main()
{
    cin >> n;
    if (n == 0)
    {
        printf("%d", 0);
        return 0;
    }
    decimal_to_binary(n);
    return 0;
}