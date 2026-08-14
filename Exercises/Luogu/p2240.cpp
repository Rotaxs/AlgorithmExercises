#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Coin
{
    int m, v;
    double p;
} coins[110]; 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> coins[i].m >> coins[i].v;
        coins[i].p = (double)coins[i].v / coins[i].m;
    }
    sort(coins + 1, coins + 1 + n, [](Coin a, Coin b) { return a.p > b.p; });
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (t >= coins[i].m)
        {
            t -= coins[i].m;
            ans += coins[i].v;
        }
        else
        {
            ans += t * coins[i].p;
            t = 0;
            break;
        }
    }
    cout << fixed << setprecision(2);
    cout << ans << '\n';
    return 0;
}