#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int l, n, k;
int a[100010];

bool check(int x)
{
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        cnt += (a[i + 1] - a[i] - 1) / x;
    }
    return cnt <= k;
}

void solve()
{
    cin >> l >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int le = 0, ri = l + 1;
    while ((le + 1) != ri)
    {
        int m = le + ((ri - le) >> 1);
        if (!check(m)) le = m;
        else ri = m;
    }
    cout << ri << '\n';
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