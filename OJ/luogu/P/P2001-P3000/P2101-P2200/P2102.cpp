// 题解解法
#include <iostream>
using namespace std;

int main()
{
    // r[i] 表示第 i 行最大值所在的列，c[i] 表示第 i 列最小值所在的行
    int r[10], c[10], mat[10][10];
    bool flag = false;

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
            cin >> mat[i][j];
    }

    int max, min;
    for (int i = 1; i <= 5; i++)
    {
        max = mat[i][1];
        r[i] = 1;
        for (int j = 1; j <= 5; j++)
        {
            if (mat[i][j] > max)
            {
                max = mat[i][j];
                r[i] = j;
            }
        }
    }
    for (int j = 1; j <= 5; j++)
    {
        min = mat[1][j];
        c[j] = 1;
        for (int i = 1; i <= 5; i++)
        {
            if (mat[i][j] < min)
            {
                min = mat[i][j];
                c[j] = i;
            }
        }
    }

    for (int i = 1; i <= 5; i++)
    {
        if (c[r[i]] == i)
        {
            cout << i << " " << r[i] << " " << mat[i][r[i]] << "\n";
            flag = true;
        }
    }
    if (!flag)
        cout << "not found" << '\n';

    return 0;
}

// #include <iostream>
// using namespace std;

// int is_max_in_row(int r, int c, int arr[11][11], int column)
// {
//     int i;
//     int max = arr[r][c];
//     for (i = 1; i <= column; i++)
//     {
//         if (arr[r][i] > max)
//             return 0;
//     }
//     return 1;
// }

// int is_min_in_row(int r, int c, int arr[11][11], int column)
// {
//     int i;
//     int min = arr[r][c];
//     for (i = 1; i <= column; i++)
//     {
//         if (arr[r][i] < min)
//             return 0;
//     }
//     return 1;
// }

// int is_max_in_column(int r, int c, int arr[11][11], int row)
// {
//     int i;
//     int max = arr[r][c];
//     for (i = 1; i <= row; i++)
//     {
//         if (arr[i][c] > max)
//             return 0;
//     }
//     return 1;
// }

// int is_min_in_column(int r, int c, int arr[11][11], int row)
// {
//     int i;
//     int min = arr[r][c];
//     for (i = 1; i <= row; i++)
//     {
//         if (arr[i][c] < min)
//             return 0;
//     }
//     return 1;
// }

// int main()
// {
//     int row = 5, column = 5;
//     int mat[11][11];
//     int i, j, flag = 0;
//     for (i = 1; i <= row; i++)
//     {
//         for (j = 1; j <= column; j++)
//         {
//             scanf("%d", &mat[i][j]);
//         }
//     }

//     for (i = 1; i <= row; i++)
//     {
//         for (j = 1; j <= column; j++)
//         {
//             if (is_max_in_row(i, j, mat, column) && is_min_in_column(i, j, mat, row))
//             {
//                 printf("%d %d %d\n", i, j, mat[i][j]);
//                 flag = 1;
//             }
//         }
//     }
//     if (flag == 0)
//         printf("not found\n");

//     return 0;
// }
