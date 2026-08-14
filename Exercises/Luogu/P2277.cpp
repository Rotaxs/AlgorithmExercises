#include <bits/stdc++.h>
using namespace std;
const double check = 1e-6; // 实数计算误差
int ans, v[5], pm[5], f[5], g[5];
map<int, int> mp;
double num(double x, double y, int z)
{ // 计算
    switch (z)
    { // z表示运算符：0加，1减，2乘，3除
    case 0:
        return x + y;
        break;
    case 1:
        return x - y;
        break;
    case 2:
        return x * y;
        break;
    case 3:
        return x / y;
        break;
    }
}
double Abs(double p)
{ // 实数绝对值
    return (p < 0 ? -p : p);
}
int useful(int a, int b)
{ // 能不能加括号
    // 括号前面是减号、除号，加上括号要变号
    if (a % 2 == 1)
        return 1;
    if (!a)
        return (b > 1 ? 1 : 0);
    else
        return (b < 2 ? 1 : 0);
}
void mplus(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{ // map+状压去重
    int x = (a1 | a2 << 3 | a3 << 6 | a4 << 9 | a5 << 12 | a6 << 15 | a7 << 18);
    if (++mp[x] == 1)
        ans++;
}
int find(int x)
{ // x是第几个
    for (int i = 1; i <= 4; i++)
        if (f[i] == x)
            return i;
}
void count(int a, int b, int c, int d)
{                                // 暴力计算
    for (int i = 0; i <= 3; i++) // i,j,k枚举符号
        for (int j = 0; j <= 3; j++)
            for (int k = 0; k <= 3; k++)
            {
                /*		5种添括号
                        (1,2,3,4)
                        ((1,2),(3,4))
                        (1,(2,3,4))
                        ((1,(2,3)),4)
                        (1,(2,(3,4)))*/
                int u1 = useful(k, j), u2 = useful(j, i);
                if (Abs((num(num(num(a, b, i), c, j), d, k) - 24)) < check)
                    mplus(pm[find(a)], pm[find(b)], (i + 4), pm[find(c)], (j + 4), pm[find(d)], (k + 4));
                if (u1 == 1 && Abs(num(num(a, b, i), num(c, d, j), k) - 24) < check)
                    mplus(pm[find(a)], pm[find(b)], (i + 4), pm[find(c)], pm[find(d)], (j + 4), (k + 4));
                if (u1 == 1 && Abs(num(a, num(num(b, c, i), d, j), k) - 24) < check)
                    mplus(pm[find(a)], pm[find(b)], pm[find(c)], (i + 4), pm[find(d)], (j + 4), (k + 4));
                if (u2 == 1 && Abs(num(num(a, num(b, c, i), j), d, k) - 24) < check)
                    mplus(pm[find(a)], pm[find(b)], pm[find(c)], (i + 4), (j + 4), pm[find(d)], (k + 4));
                if (u1 == 1 && u2 == 1 && Abs(num(a, num(b, num(c, d, i), j), k) - 24) < check)
                    mplus(pm[find(a)], pm[find(b)], pm[find(c)], pm[find(d)], (i + 4), (j + 4), (k + 4));
            }
}
void dfs(int x)
{ // dfs求排列
    if (x > 4)
    {
        count(g[1], g[2], g[3], g[4]);
        return;
    }
    for (int i = 1; i <= 4; i++)
        if (v[i] == 0)
            v[i] = 1, g[x] = f[i], dfs(x + 1), v[i] = 0;
}
int main()
{
    for (int i = 1; i <= 4; i++)
        scanf("%d", &f[i]);
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            pm[i] = pm[i] + (f[i] < f[j] ? 1 : 0); // 排第几，用于状压判重（最大0）
    dfs(1);
    printf("%d", ans);
}

// #include <iostream>
// #include <cmath>
// #include <algorithm>

// void dfs(int step, int *cards, int *permutation,
//          int (*permutations)[4], int *vis, int *num_of_perms)
// {
//     if (step == 4)
//     {
//         for (int i = 0; i < 4; i++)
//             permutations[*num_of_perms][i] = permutation[i];
//         (*num_of_perms)++;
//         return;
//     }

//     for (int i = 0; i < 4; i++)
//     {
//         if (vis[i])
//             continue;
//         // 如果上一张牌和这张牌一样，且上一张牌没被用过（其实是回溯了，说明上一张牌的情况已经全部排完了）
//         if (i >= 1 && cards[i - 1] == cards[i] && !vis[i - 1])
//             continue;
//         vis[i] = true;
//         permutation[step] = cards[i];
//         dfs(step + 1, cards, permutation, permutations, vis, num_of_perms);
//         vis[i] = false;
//     }
// }

// void bubble_sort(int *arr, int len)
// {
//     bool swapped;
//     int temp;
//     for (int i = 0; i < len - 1; i++)
//     {
//         swapped = false;
//         for (int j = 0; j < len - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//                 swapped = true;
//             }
//         }
//         if (!swapped)
//             break;
//     }
// }

// double op(int x, double a, double b)
// {
//     if (x == 0)
//         return a + b;
//     else if (x == 1)
//         return a - b;
//     else if (x == 2)
//         return a * b;
//     return b != 0 ? a / b : 1e10;
// }

// void print_solution(int *ans, int *perm)
// {
//     double res;
//     int a, b, c, d;
//     a = perm[0];
//     b = perm[1];
//     c = perm[2];
//     d = perm[3];
//     for (int x = 0; x < 4; x++)
//     {
//         for (int y = 0; y < 4; y++)
//         {
//             for (int z = 0; z < 4; z++)
//             {
//                 // ((a op b) op c) op d
//                 res = op(z, op(y, op(x, a, b), c), d);
//                 if (fabs(res - 24) < 1e-6)
//                 {
//                     (*ans)++;
//                 }

//                 // (a op (b op c)) op d
//                 res = op(z, op(y, a, op(x, b, c)), d);
//                 if (fabs(res - 24) < 1e-6)
//                 {
//                     (*ans)++;
//                 }

//                 // a op ((b op c) op d)
//                 res = op(z, a, op(y, op(x, b, c), d));
//                 if (fabs(res - 24) < 1e-6)
//                 {
//                     (*ans)++;
//                 }

//                 // (a op b) op (c op d)
//                 res = op(z, op(x, a, b), op(y, c, d));
//                 if (fabs(res - 24) < 1e-6)
//                 {
//                     (*ans)++;
//                 }

//                 // a op (b op (c op d))
//                 res = op(z, a, op(y, b, op(x, c, d)));
//                 if (fabs(res - 24) < 1e-6)
//                 {
//                     (*ans)++;
//                 }
//             }
//         }
//     }
// }

// int main()
// {
//     int ans = 0;
//     int cards[4], vis[4] = {0};
//     int permutation[4];
//     int permutations[24][4];
//     int num_of_perms = 0;

//     for (int i = 0; i < 4; i++)
//         if (scanf("%d", cards + i) != 1)
//             return 0;

//     bubble_sort(cards, 4);

//     dfs(0, cards, permutation, permutations, vis, &num_of_perms);

//     for (int i = 0; i < num_of_perms; i++)
//     {
//         print_solution(&ans, permutations[i]);
//     }
//     printf("%d\n", ans);

//     return 0;
// }