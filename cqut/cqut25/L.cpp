#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    // 异或解法
    cout << (a ^ b ^ c) << '\n';
    // 模拟解法
    // if (a == b)
    //     cout << c << '\n';
    // else if (a == c)
    //     cout << b << '\n';
    // else if (b == c)
    //     cout << a << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}