#include <iostream>
using namespace std;

/*
十六进制数匹配

S0 - 起始状态，空串
S1 - 0（可能是 0x风格 ，也可能是 H 风格）
S2 - 0x
S3 - 0xn    accept
S4 - 0n/n
S5 - 0nH/nH accept
S6 - Error

index  0   1        2          3     4
输入    0   X   0-9;a-f;A-F     H   other
S0    S1  Err      S4         Err   Err
S1    S4  S2       S4         S5    Err
S2    S3  Err      S3         Err   Err
S3    S3  Err      S3         Err   Err  accept
S4    S4  Err      S4         S5    Err
S5   Err  Err     Err         Err   Err  accept
Err   Err  Err     Err         Err   Err

*/

#define STATUS_COUNT 7
#define ALPHA_COUNT 5

typedef enum status
{
    S0 = 0,
    S1,
    S2,
    S3, // 0x 风格十六进制数的可接受状态
    S4,
    S5, // H 风格十六进制数的可接受状态
    Err
} status;

status delta[STATUS_COUNT][ALPHA_COUNT] = {
    {S1, Err, S4, Err, Err},
    {S4, S2, S4, S5, Err},
    {S3, Err, S3, Err, Err},
    {S3, Err, S3, Err, Err},
    {S4, Err, S4, S5, Err},
    {Err, Err, Err, Err, Err},
    {Err, Err, Err, Err, Err}};

int get_input_type(char ch)
{
    if (ch == '0')
        return 0;
    if (ch == 'X' || ch == 'x')
        return 1;
    if ((ch >= '1' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))
        return 2;
    if (ch == 'H' || ch == 'h')
        return 3;
    return 4;
}

int main()
{
    const char *test_str[5] = {"0xAF", "FF1H", "0X00A", "0000H", "0X0000H"};
    status s;
    for (int i = 0; i < 5; i++)
    {
        s = S0;
        const char *p = test_str[i];
        for (; *p != '\0'; p++)
        {
            s = delta[s][get_input_type(*p)];
        }
        if (s == S3 || s == S5)
            cout << "accepted" << '\n';
        else
            cout << "unaccepted" << '\n';
    }
}