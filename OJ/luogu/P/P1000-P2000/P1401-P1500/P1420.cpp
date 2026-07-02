#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << 1 << '\n';
        return 0;
    }
    int cur, la;
    int ans = 0, temp = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        if (i != 0)
        {
            if (cur - la == 1 && i != n - 1)
            {
                temp++;
            }
            else
            {
                if (cur - la == 1 && i == n - 1)
                    temp++;
                ans = max(ans, temp);
                temp = 1;
            }
        }
        la = cur;
    }

    cout << ans << '\n';
    return 0;
}