#include <bits/stdc++.h>
using namespace std;

typedef __int128 int128;
typedef long long ll;
int128 ans = 0;

// void dfs(ll xs, ll ys, ll xe, ll ye)
// {
//     int128 lenx = xe - xs + 1;
//     int128 leny = ye - ys + 1;
//     if (lenx == 1 || leny == 1)
//     {
//         if (lenx == 1)
//         {
//             ans += leny * 4;
//         }
//         else if (leny == 1)
//         {
//             ans += lenx * 4;
//         }
//         return;
//     }
//     if (lenx == 2 || leny == 2)
//     {
//         if (lenx == 2)
//         {
//             ans += leny / 2 * 8;
//             if (leny & 1)
//             {
//                 ans += 8;
//             }
//         }
//         else if (leny == 2)
//         {
//             ans += lenx / 2 * 8;
//             if (lenx & 1)
//             {
//                 ans += 8;
//             }
//         }
//         return;
//     }
//     if (lenx < leny)
//     {
//         ans += lenx * 4;
//         dfs(xs, ys + lenx, xe, ye);
//     }
//     else if (lenx > leny)
//     {
//         ans += leny * 4;
//         dfs(xs + leny, ys, xe, ye);
//     }
//     else
//     {
//         ans += (lenx + leny) * 2;
//     }
// }

void dfs(ll xs, ll ys, ll xe, ll ye)
{
    int128 lenx = xe - xs + 1;
    int128 leny = ye - ys + 1;
    ll d;
    if (lenx == leny) ans += (lenx + leny) * 2;
    else if (lenx > leny)
    {
        d = lenx / leny;
        ans += leny * 4 * d;
        if (lenx % leny != 0)
            dfs(xs + d * leny, ys, xe, ye);
    }
    else
    {
        d = leny / lenx;
        ans += lenx * 4 * d;
        if (leny % lenx != 0)
            dfs(xs, ys + d * lenx, xe, ye);
    }
}

void solve()
{
    ll x, y;
    cin >> x >> y;
    dfs(1, 1, x, y);
    cout << (ll)ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();
    
    return 0;
}