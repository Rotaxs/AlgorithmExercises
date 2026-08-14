#include <bits/stdc++.h>
using namespace std;
int jisuan(char c[])
{
    int temp = 0;
    // for (int i = 0; c[i] != '\0'; i++)
    for (int i = 0; i < strlen(c) - 1; i++)
    {
        if (c[i] == 'V' && c[i + 1] == 'K')
            temp++;
    }
    return temp;
}
int main()
{
    int n, maxn = 0;
    scanf("%d", &n);
    getchar();
    // cin >> n;
    char c[105];
    fgets(c, n + 1, stdin);
    int index = strcspn(c, "\n");
    c[index] = '\0';
    cout << index << '\n';

    // maxn = max(maxn, jisuan(c));
    // for (int i = 0; i < strlen(c); i++)
    // {
    //     if (c[i] == 'V')
    //         c[i] = 'K';
    //     else
    //         c[i] = 'V';
    //     maxn = max(maxn, jisuan(c));
    //     if (c[i] == 'V')
    //         c[i] = 'K';
    //     else
    //         c[i] = 'V';
    // }
    // printf("%d", maxn);
    return 0;
}