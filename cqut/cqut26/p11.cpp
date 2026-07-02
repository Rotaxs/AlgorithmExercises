#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int a[N], d[N];
ll dp[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    dp[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
    {
        if (i + d[i] + 1 <= n)
            dp[i] = max(dp[i + 1], dp[i + d[i] + 1] + a[i]);
        else
            dp[i] = max(dp[i + 1], dp[n + 1] + a[i]);
    }
    cout << dp[1] << '\n';
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