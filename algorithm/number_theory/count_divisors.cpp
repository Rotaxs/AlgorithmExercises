#include <iostream>
using namespace std;

int count_divisors(int n)
{
    int ans = 1;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            // 分解质因数
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            ans *= (cnt + 1);
        }
    }
    // 如果 n > 1，说明 n 还有一个大质数因子
    if (n > 1) ans *= 2;
    return ans;
}

int main()
{
    cout << count_divisors(6);
    return 0;
}