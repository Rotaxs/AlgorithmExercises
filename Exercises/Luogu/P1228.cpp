#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(ll x, ll y, ll a, ll b, ll l)
{
    
}

void solve()
{
    int k; cin >> k;
    int x, y; cin >> x >> y;

    function<void(ll, ll, ll, ll, ll)> dfs = [&](ll x, ll y, ll a, ll b, ll l)
    {
        if (l == 1) return;
        if (x - a <= l / 2 - 1 && y - b <= l / 2 - 1)
        {
            printf("%lld %lld 1\n", a + l / 2, b + l / 2);
            dfs(x, y, a, b, l / 2);
            dfs(a + l / 2 - 1, b + l / 2, a, b + l / 2, l / 2);
            dfs(a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
            dfs(a + l / 2, b + l / 2, a + l / 2, b + l / 2, l / 2);
        }
        else if (x - a <= l / 2 - 1 && y - b > l / 2 - 1)
        {
            printf("%lld %lld 2\n", a + l / 2, b + l / 2 - 1);
            dfs(a + l / 2 - 1, b + l / 2 - 1, a, b, l / 2);
            dfs(x, y, a, b + l / 2, l / 2);
            dfs(a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
            dfs(a + l / 2, b + l / 2, a + l / 2, b + l / 2, l / 2);
        }
        else if (x - a > l / 2 - 1 && y - b <= l / 2 - 1)
        {
            printf("%lld %lld 3\n", a + l / 2 - 1, b + l / 2);
            dfs(a + l / 2 - 1, b + l / 2 - 1, a, b, l / 2);
            dfs(a + l / 2 - 1, b + l / 2, a, b + l / 2, l / 2);
            dfs(x, y, a + l / 2, b, l / 2);
            dfs(a + l / 2, b + l / 2, a + l / 2, b + l / 2, l / 2);
        }
        else
        {
            printf("%lld %lld 4\n", a + l / 2 - 1, b + l / 2 - 1);
            dfs(a + l / 2 - 1, b + l / 2 - 1, a, b, l / 2);
            dfs(a + l / 2 - 1, b + l / 2, a, b + l / 2, l / 2);
            dfs(a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
            dfs(x, y, a + l / 2, b + l / 2, l / 2);
        }
    };
    dfs(x, y, 1, 1, pow(2, k));
}

int main()
{
    
    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();
    
    return 0;
}