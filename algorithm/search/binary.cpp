#include <iostream>
using namespace std;

// int arr[] = {3, 4, 4, 5, 5, 5, 6, 7};

// // 查找第一个大于5的元素
// int binary1()
// {
//     int l = -1, r = 8;
//     int m;
//     while ((l + 1) != r)
//     {
//         m = (l + r) / 2;
//         if (arr[m] <= 5)
//             l = m;
//         else
//             r = m;
//     }
//     return r;
// }

// // 找到最后一个小于等于5的元素
// // 在最后一个小于等于5的元素的右边画一根分界线
// // 最后一个小于等于5的元素在左边（蓝色区域），故最后要返回左指针
// // 蓝色区域的判断条件是 arr[m] <= 5
// int binary2()
// {
//     int l = -1, r = 8;
//     int m;
//     while ((l + 1) != r)
//     {
//         m = (l + r) >> 1;
//         if (arr[m] <= 5)
//             l = m;
//         else
//             r = m;
//     }
//     return l;
// }

// 浮点数二分
// 求一个数n的三次方根，-10000<n<10000
// 使用二分法将时间复杂度从O(n)（且有非常大的常数）级别降为O(logn)级别
void sqrt_three(int x)
{
    double l = -22, r = 22;
    double m;
    // while (r - l > 1e-8)
    // {
    //     m = (l + r) / 2;
    //     if (m * m * m < x)
    //         l = m;
    //     else
    //         r = m;
    // }

    // 使用下面的方法减少浮点数的计算
    // 2**100的数量级为1e30，因此二分的精度极高
    for (int i = 0; i < 100; i++)
    {
        m = (l + r) / 2;
        if (m * m * m < x)
            l = m;
        else
            r = m;
    }
    printf("%lf\n", l);
    printf("%lf", r);
}

int main()
{
    sqrt_three(10000);
    return 0;
}
