#include <iostream>
#include <string>
using namespace std;

// char flag[10][5][3] = {
//     "XXX", ""
// }

string flag[10][5] = {
    "XXX",
    "X.X",
    "X.X",
    "X.X",
    "XXX", // 0
    "..X",
    "..X",
    "..X",
    "..X",
    "..X", // 1
    "XXX",
    "..X",
    "XXX",
    "X..",
    "XXX", // 2
    "XXX",
    "..X",
    "XXX",
    "..X",
    "XXX", // 3
    "X.X",
    "X.X",
    "XXX",
    "..X",
    "..X", // 4
    "XXX",
    "X..",
    "XXX",
    "..X",
    "XXX", // 5
    "XXX",
    "X..",
    "XXX",
    "X.X",
    "XXX", // 6
    "XXX",
    "..X",
    "..X",
    "..X",
    "..X", // 7
    "XXX",
    "X.X",
    "XXX",
    "X.X",
    "XXX", // 8
    "XXX",
    "X.X",
    "XXX",
    "..X",
    "XXX", // 9
};

int main()
{
    int n;
    string num;
    cin >> n;
    cin >> num;
    // r 遍历每一行
    for (int r = 0; r < 5; r++)
    {
        // i 遍历每一个数字
        for (int i = 0; i < n; i++)
        {
            cout << flag[num[i] - '0'][r];
            if (i != n - 1)
                cout << '.';
        }
        cout << '\n';
    }

    return 0;
}
