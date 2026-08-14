#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    while (n--)
    {
        int k;
        cin >> k;
        ans ^= k;
    }
    cout << ans << '\n';
    return 0;
}
