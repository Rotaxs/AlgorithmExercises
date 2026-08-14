#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x, s; cin >> n >> x >> s;
    string u; cin >> u;
    int cnt_A = 0;
    for (char ch : u)
        if (ch == 'A') cnt_A++;
    int ans = 0;
    for (int i = 0; i <= cnt_A; i++)
    {
        int rem = x, seats = 0;
        int a = 0, tmp = 0;
        for (char c : u)
        {
            if (c == 'I')
            {
                if (rem > 0)
                {
                    tmp++;
                    rem--;
                    seats += s - 1;
                }
            }
            else if (c == 'A')
            {
                a++;
                if (a <= i)
                {
                    if (rem > 0)
                    {
                        tmp++;
                        rem--;
                        seats += s - 1;
                    }
                }
                else
                {
                    if (seats > 0)
                    {
                        seats--;
                        tmp++;
                    }
                }
            }
            else if (c == 'E')
            {
                if (seats > 0)
                {
                    seats--;
                    tmp++;
                }
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;

// void solve()
// {
//     int n, x, s; cin >> n >> x >> s;
//     string u; cin >> u;
//     vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
//     dp[0][0] = 0;

//     for (int i = 1; i <= n; ++i)
//     {
//         char c = u[i - 1]; 
//         for (int j = 0; j <= x; ++j)
//             dp[i][j] = dp[i - 1][j];

//         for (int j = 0; j <= x; ++j)
//         {
//             if (dp[i - 1][j] == -1) continue;

//             int k = dp[i - 1][j]; 
//             int rem = j * s - k; 

//             if ((c == 'I' || c == 'A') && j < x)
//                 dp[i][j + 1] = max(dp[i][j + 1], k + 1);
//             if ((c == 'E' || c == 'A') && rem > 0)
//                 dp[i][j] = max(dp[i][j], k + 1);
//         }
//     }
//     int ans = 0;
//     for (int i = 0; i <= x; i++)
//         ans = max(ans, dp[n][i]);
//     cout << ans << '\n';
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int t = 1;
//     cin >> t;
//     while (t--) solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;

// void solve()
// {
//     int n, x, s; cin >> n >> x >> s;
//     string u; cin >> u;
//     vector<int> dp(x + 1, -1);
//     dp[0] = 0;
//     for (char c : u)
//     {
//         vector<int> nxt_dp = dp;
//         for (int i = 0; i <= x; i++)
//         {
//             if (dp[i] == -1) continue;
//             int rem = i * s - dp[i];
//             if ((c == 'I' || c == 'A') && i < x)
//                 nxt_dp[i + 1] = max(nxt_dp[i + 1], dp[i] + 1);
//             if ((c == 'E' || c == 'A') && rem > 0)
//                 nxt_dp[i] = max(nxt_dp[i], dp[i] + 1);
//         }
//         dp = nxt_dp;
//     }
//     int ans = 0;
//     for (int i = 0; i <= x; i++)
//         ans = max(ans, dp[i]);
//     cout << ans << '\n';
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
    
//     int t = 1; 
//     cin >> t;
//     while (t--) solve();
    
//     return 0;
// }