#include <iostream>
using namespace std;

bool is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int num = 4; num <= n; num += 2)
    {
        for (int a = 2; a < num; a++)
        {
            if (is_prime(a) && is_prime(num - a))
            {
                cout << num << '=' << a << '+' << num - a << '\n';
                break;
            }
        }
    }
    return 0;
}