#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int a, b, c; cin >> a >> b >> c;
    if (a > b) cout << "Win\n";
    else if (c > b) cout << "WIN\n";
    else cout << "nowin\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}