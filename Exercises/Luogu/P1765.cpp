#include <cstdio>
int sum, i, n;
// x 表示遍历时的当前字符
// a 数组把所有字母分成了 4 组：a-o pqrs，tuv， wxyz
char x, a[] = {'a', 'p', 't', 'w', 'z' + 1};
int main()
{
    while (scanf("%c", &x) != EOF)
    {
        if (x == '\n')
            break;
        if (x >= 'a')
        {
            // 用 i 来定位字母所在的组
            // x > a[i + 1] 判断字母是否超过了下一组的首字母
            for (i = 0; i < 4 && x >= a[i + 1]; ++i)
                ;
            // i & 1 判断奇偶
            // i 为偶数即 0 或 2 时，对应的组有 3 个字母
            // i 为奇数即 1 或 3 时，对应的组有 4 个字母
            sum += (x - a[i]) % ((i & 1) + 3) + 1;
        }
        else if (x == ' ')
            ++sum;
    }
    printf("%d", sum);
    return 0;
}

// #include <iostream>
// using namespace std;

// int times[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

// int main()
// {
//     int cnt = 0;
//     char ch;
//     while (scanf("%c", &ch))
//     {
//         if (ch == '\n')
//             break;
//         if (ch == ' ')
//             cnt++;
//         else if (ch >= 'a' && ch <= 'z')
//             cnt += times[ch - 'a'];
//     }
//     cout << cnt << '\n';
//     return 0;
// }