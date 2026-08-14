#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int A, B, C;
    if (!(cin >> A >> B >> C))
        return 0;
    if (A == 0)
    {
        cout << "No!!!" << endl;
        return 0;
    } // 防御性编程

    bool exist = false;
    for (int x = 123; x <= 987; ++x)
    {
        if (x * B % A == 0 && x * C % A == 0)
        {
            int y = x * B / A;
            int z = x * C / A;
            if (y > 999 || z > 999)
                continue;

            int vis[10] = {0};
            // 统计 x, y, z 的所有数字
            vis[x / 100]++;
            vis[x / 10 % 10]++;
            vis[x % 10]++;
            vis[y / 100]++;
            vis[y / 10 % 10]++;
            vis[y % 10]++;
            vis[z / 100]++;
            vis[z / 10 % 10]++;
            vis[z % 10]++;

            bool ok = (vis[0] == 0); // 不能有0
            for (int i = 1; i <= 9; ++i)
                if (vis[i] != 1)
                    ok = false;

            if (ok)
            {
                cout << x << " " << y << " " << z << endl;
                exist = true;
            }
        }
    }

    if (!exist)
        cout << "No!!!" << endl;
    return 0;
}