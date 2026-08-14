#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int maxa = 0;
    ll sumb = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > b[i])
        {
            int c = a[i];
            a[i] = b[i];
            b[i] = c;
        }
        maxa = max(a[i], maxa);
        sumb += (ll)b[i];
    }
    ll ans = (ll)maxa + sumb;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] > maxa)
        {
            ans = max(ans, sumb + (ll)a[i]);
        }
    }
    cout << ans << '\n';
    
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