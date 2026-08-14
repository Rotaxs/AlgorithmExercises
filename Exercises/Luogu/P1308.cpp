#include <iostream>
#include <string>
using namespace std;

const int N = 1e6 + 10;
string target;
char passage[N];
int start, cnt;

enum State
{
    ST_START,
    ST_IN,
    ST_OUT
};

enum CharType
{
    T_CHAR,
    T_SPACE
};

State delta[3][2] = {
    {ST_IN, ST_OUT},
    {ST_IN, ST_OUT},
    {ST_IN, ST_OUT}};

bool is_alpha(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

char tolower(char ch)
{
    return (ch >= 'a' && ch <= 'z') ? ch : ch - 'A' + 'a';
}

int main()
{
    bool found = false;
    cin >> target;
    getchar();
    fgets(passage, N + 1, stdin);
    string word = "";
    State st = ST_START;
    for (int i = 0; i < target.length(); i++)
        target[i] = tolower(target[i]);
    for (int i = 0; passage[i] != '\0'; i++)
    {
        char ch = passage[i];
        CharType type = is_alpha(ch) ? T_CHAR : T_SPACE;
        if (type == T_CHAR)
        {
            word += tolower(ch);
        }
        else if (type == T_SPACE)
        {
            if (st == ST_IN)
            {
                if (word == target)
                {
                    if (!found)
                    {
                        found = true;
                        start = i - target.length();
                    }
                    cnt++;
                }
            }
            word = "";
        }

        st = delta[st][type];
    }
    if (found)
        cout << cnt << ' ' << start << '\n';
    else
        cout << -1 << '\n';
    return 0;
}