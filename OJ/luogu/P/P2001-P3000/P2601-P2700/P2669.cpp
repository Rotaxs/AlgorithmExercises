#include <iostream>
using namespace std;

int k;

int main()
{
    int ans = 0;

    cin >> k;

    int n;
    for (n = 0;; n++)
    {
        if (k >= n * (n + 1) / 2 && k < (n + 1) * (n + 2) / 2)
            break;
    }

    // 5 = 1 + 2 + 2
    // cout << n << "\n";

    ans = n * (n + 1) * (2 * n + 1) / 6 + (n + 1) * (k - n * (n + 1) / 2);

    cout << ans << "\n";

    return 0;
}