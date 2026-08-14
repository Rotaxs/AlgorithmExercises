#include <iostream>
#include <map>
using namespace std;

int t, n;

void solve()
{
    cin >> n;
    int color;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> color;
            mp[color]++;
        }
    }
    for (auto item : mp)
    {
        if (item.second > n * (n - 1))
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
        solve();

    return 0;
}