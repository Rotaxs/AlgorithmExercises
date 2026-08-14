#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXA = 1e5 + 10;
queue<ll> q1, q2;
int cnt[MAXA];

void solve()
{
    int n;
    cin >> n;
    int a, mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        mx = max(a, mx);
        cnt[a]++;
    }
    for (int i = 1; i <= mx; i++)
    {
        while (cnt[i] != 0)
        {
            q1.push(i);
            cnt[i]--;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        ll x, y;
        if (q2.empty() || (!q1.empty() && q1.front() <= q2.front()))
        {
            x = q1.front(); q1.pop();
        }
        else
        {
            x = q2.front(); q2.pop();
        }
        if (q2.empty() || (!q1.empty() && q1.front() <= q2.front()))
        {
            y = q1.front(); q1.pop();
        }
        else
        {
            y = q2.front(); q2.pop();
        }
        q2.push(x + y);
        ans += x + y;
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

    solve();
    
    return 0;
}