#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 510;

int dp[N][N];
int pre_one[N], pre_zero[N];
int n, L, R;
string s;

int dfs(int l, int r)
{
    if (r <= l) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int res = 0;
    for (int m = l; m < r; m++)
    {
        int c0 = pre_zero[m + 1] - pre_zero[l];
        int c1 = pre_one[r + 1] - pre_one[m + 1];
        int diff = abs(c0 - c1);
        if (diff >= L && diff <= R) 
            res = max(res, dfs(l, m) + dfs(m + 1, r) + 1);
    }
    return dp[l][r] = res;
}

void solve()
{
    cin >> n >> L >> R;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        pre_one[i + 1] = pre_one[i] + (s[i] == '1' ? 1 : 0);
        pre_zero[i + 1] = pre_zero[i] + (s[i] == '0' ? 1 : 0);
    }
    memset(dp, -1, sizeof dp);
    int ans = dfs(0, n - 1);
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