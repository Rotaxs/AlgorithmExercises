#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    while (n--)
    {
        ans++;
        if (ans % k == 0)
            n++;
    }
    cout << ans << '\n';
    return 0;
}