#include <bits/stdc++.h>
using namespace std;


int main()
{
    int a = 10000;
    // int cnt = 0;
    // while (a)
    // {
    //     cnt++;
    //     a &= (a - 1);
    // }
    // cout << cnt << '\n';
    while (1)
    {
        cout << (a % 2);
        a /= 2;
        if (a == 0) break;
    }
    
    return 0;
}