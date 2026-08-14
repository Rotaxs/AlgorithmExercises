#include <iostream>
#include <cstring>
using namespace std;

const int N = 210;
int ans[N * N] = {0};

enum State
{
    ST_START,
    ST_ZERO,
    ST_ONE
};

enum CharType
{
    T_ZERO,
    T_ONE
};

// delta[State][Chartype]
enum State delta[3][2] = {
    {ST_ZERO, ST_ONE},
    {ST_ZERO, ST_ONE},
    {ST_ZERO, ST_ONE}};

int main()
{
    int n;
    char line[N], str[N * N] = "";
    fgets(line, N + 1, stdin);
    line[strcspn(line, "\n")] = '\0';
    n = strlen(line);
    strcat(str, line);
    for (int i = 1; i < n; i++)
    {
        fgets(line, n + 2, stdin);
        line[strcspn(line, "\n")] = '\0';
        strcat(str, line);
    }

    enum State st = ST_START;
    int index = 0;
    for (char *p = str; *p != '\0'; p++)
    {
        char ch = *p;
        CharType type = ch == '0' ? T_ZERO : T_ONE;
        if (type == T_ZERO)
        {
            if (st == ST_START)
            {
                if (index == 0)
                    ans[index]++;
            }
            else if (st == ST_ONE)
                ans[++index]++;
            else if (st == ST_ZERO)
                ans[index]++;
        }
        else if (type == T_ONE)
        {
            if (st == ST_START)
            {
                if (index == 0)
                    ans[++index]++;
            }
            else if (st == ST_ONE)
                ans[index]++;
            else if (st == ST_ZERO)
                ans[++index]++;
        }
        st = delta[st][type];
    }

    cout << n << ' ';
    for (int i = 0; i <= index; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}