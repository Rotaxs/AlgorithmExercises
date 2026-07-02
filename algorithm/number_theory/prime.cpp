#include <iostream>
using namespace std;

bool is_prime01(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool is_prime02(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; (long long)i * i <= n; i++) // 减少大素数的遍历次数
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{

    return 0;
}