#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;

    for (int i = 1; i <= n * n; i++)
    {
        printf("%02d", i);
        if (i % n == 0)
            printf("\n");
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
            printf("  ");
        for (int j = 1; j <= i; j++)
            printf("%02d", i * (i - 1) / 2 + 1 + j - 1);
        printf("\n");
    }

    return 0;
}