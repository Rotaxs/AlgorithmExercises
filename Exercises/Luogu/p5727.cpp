#include <iostream>
using namespace std;

void solve(int n)
{
    if (n == 1)
    {
        printf("%d ", 1);
        return;
    }
    if (n % 2 == 0)
        solve(n / 2);
    else
        solve(n * 3 + 1);
    printf("%d ", n);
}

int main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}