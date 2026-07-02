#include <iostream>
using namespace std;

long long qpow_recursion(int a, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        long long tmp = qpow_recursion(a, n / 2);
        return tmp * tmp;
    }
    return qpow_recursion(a, n - 1) * a;
}

/*
    n = 10d = 1010b = 2^3 + 2^1

    n^10 = n^(2^3) * n^(2^1)

    当 n 的 LSB 是 0 时，a 平方
    当 n 的第 i 位为 1 时，a 变成了 a^(2^(i+1))，ret *= a
*/
// 10D = 1010B
// n = 101 a = a ^ 2
// n = 10  a = a ^ 4
// n = 1   a = a ^ 8
long long qpow(int a, int n)
{
    long long ret = 1;
    while (n)
    {
        if (n & 1) ret *= a;
        a *= a;
        n >>= 1;
    }
    return ret;
}

long long qpow(int a, int n, int p)
{
    long long ret = 1;
    while (n)
    {
        if (n & 1) ret = ret * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ret;
}

int main()
{
    cout << qpow(2, 20) << endl;
}