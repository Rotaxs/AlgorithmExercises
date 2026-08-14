#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_two_power(ll n)
{
    ll p = 1;
    for (int i = 1; i <= 30; i++)
    {
        if (p == n) return true;
        p *= 2;
    }
    return false;
}

void solve()
{
    int n, x; cin >> n >> x;
    if (x > n || x == 1)
    {
        if (is_two_power(n)) cout << "Yes\n";
        else cout << "No\n";
        return;
    }
    int k = 0, tmp = n;
    while (tmp)
    {
        k += tmp % x;
        tmp /= x;
    }
    for (int w = 1; w <= n; w <<= 1)
    {
        if (w < k) continue;
        if ((n - w) % (x - 1) == 0)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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