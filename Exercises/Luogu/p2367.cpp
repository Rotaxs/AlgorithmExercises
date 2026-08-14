#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int N = 5 * 1e6 + 10;
int n, p;
int scores[N], diff[N];

int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        cin >> scores[i];
    int x, y, z;
    for (int i = 0; i < p; i++)
    {
        cin >> x >> y >> z;
        diff[x] += z;
        diff[y + 1] -= z;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        diff[i] += diff[i - 1];
        scores[i] += diff[i];
        ans = min(ans, scores[i]);
    }
    cout << ans << '\n';

    return 0;
}