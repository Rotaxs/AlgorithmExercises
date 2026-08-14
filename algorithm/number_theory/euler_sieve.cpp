#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1000005; // 根据题目范围调整
int primes[MAXN], cnt;    // 存储找出的素数
bool is_not_prime[MAXN];  // 标记是否为合数

void get_primes(int n)
{
    is_not_prime[0] = is_not_prime[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!is_not_prime[i])
            primes[++cnt] = i;
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++)
        {
            is_not_prime[i * primes[j]] = true;
            // 保证 i * primes[j] 的最小质因子是 primes[j]
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main()
{
    get_primes(100);
    for (int i = 1; i <= 100; i++)
    {
        cout << i << ':' << is_not_prime[i] << '\n';
    }
    return 0;
}