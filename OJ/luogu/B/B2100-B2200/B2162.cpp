#include <iostream>
#include <string>
using namespace std;

long long quick_pow(long long n, int e)
{
    long long ret = 1;
    while (e)
    {
        if (e & 1)
            ret *= n;
        n *= n;
        e >>= 1;
    }
    return ret;
}

int main()
{
    string bi;
    cin >> bi;

    int len = bi.length();

    int res = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        res += (bi[i] - '0') * quick_pow(2, len - i - 1);
    }

    cout << res << '\n';

    return 0;
}