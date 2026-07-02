#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int a, b;
// const int N = 1e8 + 10;
// bool is_prime[N];
// bool is_palindrome[N];

// void init_palindrome()
// {
//     memset(is_palindrome, true, N);
//     int tmp_n, d, a[9];
//     for (int n = 10; n < N; n++)
//     {
//         tmp_n = n;
//         d = 0;
//         while (tmp_n)
//         {
//             a[d] = tmp_n % 10;
//             tmp_n /= 10;
//             d++;
//         }
//         for (int i = 0; i <= d / 2; i++)
//         {
//             if (a[i] != a[d - 1 - i])
//                 is_palindrome[n] = false;
//         }
//     }
// }

// void init_prime()
// {
//     memset(is_prime, true, N);
//     for (int i = 2; i < N; i++)
//     {
//         if (is_prime[i])
//         {
//             for (int j = i * 2; j <= N; j += i)
//             {
//                 is_prime[j] = false;
//             }
//         }
//     }
//     is_prime[0] = is_prime[1] = false;
// }

bool is_palindrome(int n)
{
    // int tmp_n = n, a[10], d = 0;
    // while (tmp_n)
    // {
    //     a[d] = tmp_n % 10;
    //     tmp_n /= 10;
    //     d++;
    // }
    // for (int i = 0; i <= d / 2; i++)
    // {
    //     if (a[i] != a[d - 1 - i])
    //         return false;
    // }
    // return true;

    int num = n, rev_num = 0;
    while (num)
    {
        rev_num = rev_num * 10 + num % 10;
        num /= 10;
    }
    return n == rev_num;
}

bool is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    // init_palindrome();
    // init_prime();

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    // 大于 2 的偶数不可能是素数
    if (a % 2 == 0)
        a++;
    for (int i = a; i <= b; i += 2)
    {
        if (a - 1 == 2)
            cout << 2 << '\n';
        if ((i >= 1000 && i <= 9999) || (i >= 100000 && i <= 999999))
            continue;

        // 先判断回文数O(log n)，再判断质数O(sqrt(n))
        if (is_palindrome(i) && is_prime(i))
            cout << i << '\n';
    }

    return 0;
}