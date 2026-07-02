#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

/**
 * 复杂度分析：
 * 时间：O(sqrt(R) + (R-L+1) log log sqrt(R))
 * 空间：O(sqrt(R) + (R-L+1))
 */

const int MAX_SQRT = 50005; 
const int MAX_RANGE = 1000005; // 区间长度 R - L + 1

int primes[MAX_SQRT], cnt;
bool is_not_prime_small[MAX_SQRT];  // 用于筛 [1, sqrt(R)]
bool is_not_prime_range[MAX_RANGE]; // 用于映射 [L, R]

void sieve_small(int n)
{
    memset(is_not_prime_small, 0, sizeof(is_not_prime_small));
    is_not_prime_small[0] = is_not_prime_small[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!is_not_prime_small[i]) primes[++cnt] = i;
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++)
        {
            is_not_prime_small[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void segmented_sieve(ll l, ll r)
{
    if (l < 2) l = 2; // 1 既不是质数也不是合数
    if (l > r) return;
    memset(is_not_prime_range, 0, sizeof(is_not_prime_range));

    for (int i = 1; i <= cnt; i++)
    {
        ll p = primes[i];
        if (p * p > r) break; // 说明 p 无法筛掉区间内任何新合数
        // 找到区间内第一个 >= l 且是 p 的倍数的数
        ll start = (l + p - 1) / p * p;
        // 如果 start 就是 p 本身，必须从 p 的 2 倍开始筛（因为 p 是质数）
        if (start == p) start += p;

        for (ll j = start; j <= r; j += p)
            is_not_prime_range[j - l] = true;
    }
}

int main()
{
    ll l, r;
    while (cin >> l >> r)
    {
        sieve_small(MAX_SQRT - 1);
        segmented_sieve(l, r);

        int ans = 0;
        for (ll i = 0; i <= r - l; i++)
        {
            if (!is_not_prime_range[i])
            {
                // 这里的 i + l 就是原数字
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}