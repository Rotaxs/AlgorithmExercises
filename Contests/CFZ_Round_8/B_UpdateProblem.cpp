#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    long long n, a, b;
    cin >> n >> a >> b;

    if (n == 0)
    {
        // n = 0 情况
        long long ans = (a + 2 * b) / (2 * b + 1); // 向上取整用整数公式
        cout << ans << endl;
    }
    else if (n > 0)
    {
        // n > 0 情况
        long long t;
        if (a - 2 * n * b <= 0)
            t = 0;
        else
            t = (a - 2 * n * b + 2 * b) / (2 * b + 1); // 向上取整
        cout << t + n << endl;
    }
    else
    { // n < 0
        long long t;
        if (a + 2 * n + 2 * n * b <= 0)
            t = 0;
        else
            t = (a + 2 * n + 2 * n * b + 2 * b) / (2 * b + 1); // 向上取整
        cout << t - n << endl;
    }
}

int main()
{
    int c, t;
    cin >> c >> t;
    while (t--) solve();
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// int c, t;

// bool check(ll m_in, ll n_in, ll a_in, ll b_in)
// {

//     __int128 m = m_in;
//     __int128 n = n_in;
//     __int128 a = a_in;
//     __int128 b = b_in;
//     if (n > m || n < -m)
//         return false;

//     if (b == 0)
//     {
//         return (n + a <= m);
//     }

//     __int128 c1 = (m - n) + 2 * b * m;
//     __int128 c2 = (m + n) + 2 * (b - 1) * m;

//     return a <= (c1 > c2 ? c1 : c2);
// }

// void solve()
// {
//     ll n, a, b;
//     cin >> n >> a >> b;
//     ll ans = 0;
//     ll l = -1, r = 4e18;
//     while ((l + 1) != r)
//     {
//         ll mid = l + ((r - l) >> 1);
//         // 判断是否经过一定的操作得到的最大值为 mid 或小于 mid
//         if (check(mid, n, a, b))
//             ans = r = mid;
//         else
//             l = mid;
//     }
//     cout << ans << '\n';
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> c >> t;
//     while (t--)
//         solve();
//     // solve();
//     return 0;
// }