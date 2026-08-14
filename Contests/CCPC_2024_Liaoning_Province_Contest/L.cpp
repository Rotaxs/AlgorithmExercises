#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;

ll k;

// bool check(ll x)
// {
//     ll f = 4, h = 100;
//     ll diff = x - 2024;
//     ll cnt_yeap = 0;
//     // for (; diff / h != 0 || diff / f != 0; f *= 100, h *= 100)
//     for (; diff / f != 0; f *= 100, h *= 100)
//     {
//         cnt_yeap += diff / f;
//         cnt_yeap -= diff / h;
//     }
//     ll rem = diff - cnt_yeap;
//     return rem >= k;
// }

bool check(i128 x)
{
    i128 f = 4, h = 100;
    i128 cnt_yeap = 0;
    for (; x / f != 0 || x / h != 0; f *= 100, h *= 100)
    {
        cnt_yeap += x / f;
        cnt_yeap -= x / h;
    }
    i128 rem = x - cnt_yeap - 1533;
    return rem >= k;
}

void solve()
{
    cin >> k;
    ll L = 2023, R = LONG_LONG_MAX;
    while ((L + 1) != R)
    {
        ll m = L + ((R - L) >> 1);
        if (check(m)) R = m;
        else L = m;
    }
    cout << R << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}