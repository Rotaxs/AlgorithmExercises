#include <iostream>
#include <cstring>
using namespace std;

const int N = 12;
char src[N][N], dst[N][N], temp[N][N], middle[N][N];
int n;

// --- 核心变换逻辑：不再直接判断，而是执行矩阵转换 ---

void do_rotate90(char in[N][N], char out[N][N])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            out[j][n - i - 1] = in[i][j];
}

void do_flip(char in[N][N], char out[N][N])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            out[i][n - 1 - j] = in[i][j];
}

// 基于 90 度叠加实现其他旋转，保证逻辑简洁
void do_rotate180(char in[N][N], char out[N][N])
{
    char t[N][N];
    do_rotate90(in, t);
    do_rotate90(t, out);
}

void do_rotate270(char in[N][N], char out[N][N])
{
    char t[N][N];
    do_rotate180(in, t);
    do_rotate90(t, out);
}

// --- 包装函数：适配函数指针数组 bool (*ops[])() ---

bool isSame(char a[N][N], char b[N][N])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != b[i][j])
                return false;
    return true;
}

bool op1()
{
    do_rotate90(src, temp);
    return isSame(temp, dst);
}
bool op2()
{
    do_rotate180(src, temp);
    return isSame(temp, dst);
}
bool op3()
{
    do_rotate270(src, temp);
    return isSame(temp, dst);
}
bool op4()
{
    do_flip(src, temp);
    return isSame(temp, dst);
}

bool op5()
{
    // 组合：先翻转，再进行 1-3 之一的旋转
    do_flip(src, middle); // 先翻转到中间矩阵

    do_rotate90(middle, temp);
    if (isSame(temp, dst))
        return true;
    do_rotate180(middle, temp);
    if (isSame(temp, dst))
        return true;
    do_rotate270(middle, temp);
    if (isSame(temp, dst))
        return true;
    return false;
}

bool op6() { return isSame(src, dst); }
bool op7() { return true; } // 始终为真，作为保底

bool (*ops[7])() = {op1, op2, op3, op4, op5, op6, op7};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    if (!(cin >> n))
        return 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> src[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dst[i][j];

    for (int i = 0; i < 7; i++)
    {
        if (ops[i]())
        {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}