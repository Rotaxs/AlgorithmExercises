// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;

// int n, k;
// ll ans = 0;
// vector<pair<int, bool>> s;

// // void dfs(int step, int prev)
// // {
// //     if (step == n)
// //     {
// //         ans++;
// //         return;
// //     }
// //     for (int i = 0; i < n; i++)
// //     {
// //         if (s[i].second) continue;
// //         if (abs(s[i].first - prev) <= k) continue;
// //         s[i].second = true;
// //         dfs(step + 1, s[i].first);
// //         s[i].second = false;
// //     }   
// // }

// ll dp[1 << 16][16];

// ll dfs(int mask, int prev)
// {
//     if (mask == (1 << n) - 1)
//         return 1;
//     if (dp[mask][prev] != -1)
//         return dp[mask][prev];
//     ll res = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         if (mask & (1 << i)) continue;
//         if (abs(s[i].first - s[prev].first) <= k) continue;
//         res += dfs(mask | (1 << i), i);
//     }
//     return dp[mask][prev] = res;
// }

// void solve()
// {
//     cin >> n >> k;
    
//     for (int i = 1; i <= n; ++i)
//     {
//         int a; cin >> a;
//         s.push_back({a, false});
//     }

//     // for (int i = 0; i < n; ++i)
//     // {
//     //     s[i].second = true;
//     //     dfs(1, s[i].first);
//     //     s[i].second = false;
//     // }
//     // cout << ans << '\n';

//     memset(dp, -1, sizeof dp);
//     for (int i = 0; i < n; ++i)
//     {
//         ans += dfs(1 << i, i);
//     }
//     cout << ans << endl;
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
    
//     int t = 1; 
//     // cin >> t;
//     while (t--) solve();
    
//     return 0;
// }

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

int n, k;
ll ans = 0;
vector<int> s;

ll dp[1 << 16][16];

ll dfs(int mask, int prev)
{
    if (mask == (1 << n) - 1)
        return 1;
    if (dp[mask][prev] != -1)
        return dp[mask][prev];
    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (mask & (1 << i)) continue;
        if (abs(s[i] - s[prev]) <= k) continue;
        res += dfs(mask | (1 << i), i);
    }
    return dp[mask][prev] = res;
}

void solve()
{
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i)
    {
        int a; cin >> a;
        s.push_back(a);
    }
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; ++i)
    {
        ans += dfs(1 << i, i);
    }
    cout << ans << endl;
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