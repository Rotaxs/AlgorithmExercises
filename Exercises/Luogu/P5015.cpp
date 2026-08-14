#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    char s[100];
    int ans = 0;
    fgets(s, 101, stdin);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ' && s[i] != '\n')
            ans++;
    }
    cout << ans << '\n';
    return 0;
}