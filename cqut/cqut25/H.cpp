#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m, k;
    ll a, b;
    cin >> n >> m >> k;
    // 共采矿 k 次，那么横纵采矿次数为 (k + 1) / 2 和 k / 2
    // 考虑不等式当 a > b 且 c > d 时必有  ac + bd > ad + bc
    // 即如果横向采矿次数 (k + 1) / 2，需保证 m > n，反之同理
    if (n >= m)
    {
        // 注意不能超过边长
        a = min((k + 1) / 2, m);
        b = min(k / 2, n);
        cout << n * a + m * b - a * b;
    }
    else
    {
        a = min((k + 1) / 2, n);
        b = min(k / 2, m); 
        cout << m * a + n * b - a * b;
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();


    return 0;
}