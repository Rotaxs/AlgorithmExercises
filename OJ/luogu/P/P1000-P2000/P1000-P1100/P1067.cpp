#include <iostream>
#include <cmath>
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int con, abs_con;
    if (n == 0)
    {
        cin >> con;
        cout << con;
        return 0;
    }
    for (int i = n; i >= 0; i--)
    {
        cin >> con;

        abs_con = abs(con);
        // 输出符号
        if (con > 0 && i != n)
            cout << "+";
        if (con < 0)
            cout << "-";

        // 输出系数
        if (abs_con > 1)
            cout << abs_con;
        if (i == 0 && abs_con == 1)
            cout << abs_con;

        // 输出 x
        if (i > 1 && con != 0)
            cout << "x^" << i;
        if (i == 1 && con != 0)
            cout << "x";

        // if (con != 0)
        // {
        //     if (i == n)
        //     {
        //         if (con == 1)
        //             cout << "x^" << i;
        //         else if (con == -1)
        //             cout << "-x^" << i;
        //         else
        //             cout << con << "x^" << i;
        //         continue;
        //     }
        //     if (i == 0)
        //     {
        //         if (con > 0)
        //             cout << "+" << con;
        //         else
        //             cout << con;
        //         continue;
        //     }
        //     if (i == 1)
        //     {
        //         if (con > 0)
        //         {
        //             if (con == 1)
        //                 cout << "+" << "x";
        //             else
        //                 cout << "+" << con << "x";
        //         }
        //         else
        //         {
        //             if (con == -1)
        //                 cout << "-x";
        //             else
        //                 cout << con << "x";
        //         }
        //         continue;
        //     }
        //     if (con > 0)
        //     {
        //         if (con == 1)
        //             cout << "+" << "x^" << i;
        //         else
        //             cout << "+" << con << "x^" << i;
        //     }
        //     else
        //     {
        //         if (con == -1)
        //             cout << "-x^" << i;
        //         else
        //             cout << con << "x^" << i;
        //     }
        // }
    }

    return 0;
}