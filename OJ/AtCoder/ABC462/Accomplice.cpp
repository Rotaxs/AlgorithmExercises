#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e6 + 10;
int diff[N];

void solve()
{
    int n, d; cin >> n >> d;
    int maxr = 0;
    for (int i = 1; i <= n; i++)
    {
        int l, r; cin >> l >> r;
        if (r - d >= l)
        {
            diff[l]++;
            diff[r - d + 1]--;
        }
        maxr = max(r, maxr);
    }
    ll ans = 0, pre = 0;
    for (int i = 1; i <= maxr; i++)
    {
        pre += diff[i];
        ans += pre * (pre - 1) / 2;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;

// void solve()
// {
//     int n, d;
//     cin >> n >> d;

//     map<ll, ll> diff;

//     for (int i = 1; i <= n; i++)
//     {
//         ll l, r;
//         cin >> l >> r;
//         ll L = l;
//         ll R = r - d;
//         if (L <= R)
//         {
//             diff[L]++;
//             diff[R + 1]--;
//         }
//     }

//     ll ans = 0;
//     ll pre = 0;
//     ll last = -1;

//     for (auto [x, v] : diff)
//     {
//         if (last != -1)
//         {
//             ll len = x - last;
//             ans += len * pre * (pre - 1) / 2;
//         }
//         pre += v;
//         last = x;
//     }

//     cout << ans << '\n';
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     solve();
//     return 0;
// }