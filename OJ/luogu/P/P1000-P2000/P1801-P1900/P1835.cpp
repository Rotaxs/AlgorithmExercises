#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAX_SQRT = 50000;    // sqrt(2^31-1) 约 46340
const int MAX_RANGE = 1000005;

int primes[MAX_SQRT], cnt;
bool is_not_prime[MAX_SQRT];
bool range_not_prime[MAX_RANGE]; // 映射区间 [L, R]

void sieve(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!is_not_prime[i])
            primes[++cnt] = i;
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++)
        {
            is_not_prime[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main()
{
    ll l, r;
    cin >> l >> r;
    if (l == 1)
        l = 2; // 1既不是质数也不是合数

    sieve(MAX_SQRT - 1);

    // 用小质数筛去 [L, R] 范围内的合数
    for (int i = 1; i <= cnt; i++)
    {
        ll p = primes[i];
        // 找到大于等于 L 的第一个 p 的倍数
        // 不能从 p 自身开始筛（如果 p 在 [L, R] 内），要从 2*p 开始
        ll start = max(2LL, (l + p - 1) / p) * p;
        for (ll j = start; j <= r; j += p)
            range_not_prime[j - l] = true; // 坐标偏移映射
    }

    int ans = 0;
    for (ll i = l; i <= r; i++)
        if (!range_not_prime[i - l]) ans++;
    cout << ans << endl;
    return 0;
}