#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(vector<ll> &a, int n)
{
    ll cur, prev;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            prev = a[i];
            continue;
        }
        else cur = a[i];
        if (cur < prev)
            return false;
        prev = cur;
    }
    return true;
}

void solve()
{
    int n; cin >> n;
    vector<ll> a(n + 1);
    vector<int> pre(n + 1);
    bool ok = true;;
    ll cur, prev;
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = max((ll)pre[i - 1], a[i]);
    }
    if (check(a, n))
    {
        cout << "YES\n";
        return;
    }
    ll mx = 0;
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, pre[i] - a[i]);
    }
    prev = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] < prev)
        {
            a[i] += mx;
        }
        prev = a[i];
    }
    if (check(a, n)) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}