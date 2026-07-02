#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief 对 N 进行质因数分解，并计算约数个数和约数和。
 * @param n 输入的正整数。由于数据范围高达 2*10^9，这里使用 int (或 long long if N > 2*10^9)
 * @param divisor_count 输出：约数个数 (int)
 * @param divisor_sum 输出：约数和 (long long，防止溢出)
 */
void get_divisors_info(int n, int &divisor_count, long long &divisor_sum)
{

    // 边界情况：1 的约数个数是 1，约数和是 1
    if (n == 1)
    {
        divisor_count = 1;
        divisor_sum = 1;
        return;
    }

    // 初始化结果
    divisor_count = 1;
    divisor_sum = 1;
    int temp_n = n; // 使用临时变量进行质因数分解

    // 1. 试除法分解质因数：从 2 开始，到 sqrt(temp_n)
    for (int p = 2; (long long)p * p <= temp_n; ++p)
    {
        if (temp_n % p == 0)
        {
            int exponent = 0; // 质因数 p 的指数 e
            // sum_of_powers 存储 (1 + p + p^2 + ... + p^e) 的和。
            // 必须使用 long long 避免中间计算溢出
            long long sum_of_powers = 1;
            long long p_to_e = 1; // p^0

            // 循环除以 p，直到不能整除
            while (temp_n % p == 0)
            {
                exponent++;
                temp_n /= p;

                // 递推计算约数和的项： sum_of_powers = 1 + p + p^2 + ... + p^e
                p_to_e *= p;
                sum_of_powers += p_to_e;
            }

            // a) 更新约数个数： (e + 1) 相乘
            divisor_count *= (exponent + 1);

            // b) 更新约数和：乘以 (1 + p + ... + p^e)
            divisor_sum *= sum_of_powers;
        }
    }

    // 2. 处理剩余部分：如果 temp_n > 1，则 temp_n 本身是一个大质数 p_k
    if (temp_n > 1)
    {
        // 最后一个质因数 p_k，指数 e_k = 1

        // a) 约数个数：乘以 (1 + 1) = 2
        divisor_count *= 2;

        // b) 约数和：乘以 (1 + p_k)
        // 1LL 确保 temp_n 被提升到 long long 进行加法，避免溢出
        divisor_sum *= (1LL + temp_n);
    }
}

int main()
{
    // 优化 C++ I/O 性能
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cout << "请输入一个正整数 n: ";
    if (!(cin >> n))
        return 0;

    int count = 0;
    long long sum = 0;

    get_divisors_info(n, count, sum);

    // 输出：
    cout << "约数个数: " << count << "\n";
    cout << "约数之和: " << sum << "\n";

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <utility>
// #include <cmath>
// using namespace std;

// unordered_map<int, int> divided_n;

// // 分解质因数
// void div_prime_factor(int n)
// {
//     if (n == 1)
//         return;
//     for (int i = 2; i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             n /= i;
//             divided_n[i]++;
//             div_prime_factor(n);
//             break;
//         }
//     }
// }

// int get_factor_cnt()
// {
//     int ans = 1;
//     for (auto e : divided_n)
//     {
//         ans *= e.second + 1;
//     }
//     return ans;
// }

// long long qpow(long long a, long long n)
// {
//     if (n == 0)
//         return 1;
//     if (n % 2 == 0)
//     {
//         long long tmp = qpow(a, n / 2);
//         return tmp * tmp;
//     }
//     if (n % 2 == 1)
//         return qpow(a, n - 1) * a;
// }

// int get_factor_sum()
// {
//     int ans = 1, g;
//     for (auto e : divided_n)
//     {
//         // g = 0;
//         // for (int i = 0; i <= e.second; i++)
//         // {
//         //     g += qpow(e.first, i);
//         //     // g += pow(e.first, i);
//         // }
//         // ans *= g;

//         ans *= (qpow(e.first, e.second + 1) - 1) / (e.first - 1);
//     }
//     return ans;
// }

// void print_map()
// {
//     for (auto e : divided_n)
//     {
//         cout << e.first << " " << e.second << endl;
//     }
// }

// int main()
// {
//     div_prime_factor(28);
//     cout << get_factor_cnt() << endl;
//     cout << get_factor_sum() << endl;
//     // print_map();
//     return 0;
// }