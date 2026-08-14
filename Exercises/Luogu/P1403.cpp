#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int cnt[1000010];

void solve1()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            cnt[j]++;
        }   
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += cnt[i];
    }
    cout << ans << '\n';
}

void solve2()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (ll j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                ans++;
                if (j * j != i) ans++;
            }
        }
    }
    cout << ans << '\n';
}

void solve3()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            ans++;
        }
    }
    cout << ans << '\n';
}

void solve4()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += n / i;
    }
    cout << ans << '\n';
}

void solve5()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (int l = 1, r; l <= n; l = r + 1)
    {
        // 计算当前块的 n / i 的值
        int k = n / l;
        // k = 0 那么后面就没有新的贡献了
        if (k == 0) r = n;
        // k = n / r; r = n / k
        else r = min(n, n / k);
        ans += (r - l + 1) * k;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--) solve();

    solve5();
    
    return 0;
}