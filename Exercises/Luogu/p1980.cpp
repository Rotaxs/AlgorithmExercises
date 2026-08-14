// 题解：数位DP
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, x, m = 1, ans = 0;
    scanf("%d%d", &n, &x);
    while (m <= n)
    {
        // b 从个位开始到最高位，且 b 在第几位，m 就是 10 的几-1次方
        // b就为那一位数，a为b左边的数，c为b右边的数
        int a = n / (m * 10), b = n / m % 10, c = n % m;
        if (x)
        {
            if (b > x)
                ans += (a + 1) * m;
            if (b == x)
                // 例如 7294，x=9：b=9 时 m=10，从 0090,0190,...,7190,7190 共有 72*10 （72 表示从 00 到 71，10 表示个位从 0 到 9），然后再从 7290 -- 7294 共 4 + 1 个
                ans += a * m + c + 1;
            if (b < x)
                // 例如 7294，x=4：b=2 时 m=100，a=7，c=94，从 0400,1400,...,6400 共 a 个，乘 100 表示对于每一个 a 十位和个位有 100 种组合
                ans += a * m;
        }
        else
        { // x=0的情况和x！=0的情况有所不同
            if (b)
                ans += a * m;
            else
                ans += (a - 1) * m + c + 1;
        }
        m *= 10;
    }
    printf("%d\n", ans);
    return 0;
}

// #include <iostream>
// using namespace std;

// int n, x;

// int main()
// {
//     cin >> n >> x;

//     int ans = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         int tmp = i;
//         while (tmp != 0)
//         {
//             if (tmp % 10 == x)
//                 ans++;
//             tmp /= 10;
//         }
//     }

//     cout << ans << "\n";

//     return 0;
// }