// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// void solve()
// {
//     int n;
//     cin >> n;
//     if (n % 4 == 0) cout << "Bob\n";
//     else cout << "Alice\n";
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int t;
//     cin >> t;
//     while (t--) solve();

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100005;
int primes[MAXN], cnt;
bool is_not_prime[MAXN];
int win[MAXN];

// 欧拉筛：将 1 ~ n 的质数存入 primes 数组
void get_primes(int n)
{
    is_not_prime[0] = is_not_prime[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!is_not_prime[i]) primes[++cnt] = i;
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++)
        {
            is_not_prime[i * primes[j]] = true;
            // 保证 i * primes[j] 的最小质因子是 primes[j]
            if (i % primes[j] == 0) break;
        }
    }
}

void build()
{
    get_primes(MAXN);
    win[0] = false;
    for (int i = 1; i <= MAXN; i++)
    {
        // Alice 先手取 1
        // 发现 i - 1 个石子时先手不能赢，也就是 Bob 不能赢
        // 所以 Alice 必赢
        if (!win[i - 1])
        {
            win[i] = true;
            continue;
        }
        // 遍历所有的质数
        for (int j = 1; j <= cnt && primes[j] <= i; j++)
        {
            // Alice 先手取了某个质数
            // 发现 i - 这个质数先手不能赢，也就是 Bob 必败
            // 所以 Alice 必赢
            if (!win[i - primes[j]])
            {
                win[i] = true;
                break;
            }
        }
        // 如果所有质数找完 Alice 都不能赢，那么 Bob 必赢
    }
}

void solve()
{
    int n;
    cin >> n;
    if (win[n]) cout << "Alice\n";
    else cout << "Bob\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build();

    int t;
    cin >> t;
    while (t--) solve();


    return 0;
}