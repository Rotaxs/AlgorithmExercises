#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    int zero = 0, one = 0, two = 0;
    for (int i = 1; i <= n; i++)
    {
        int w; cin >> w;
        if (w == 0)
            zero++;
        else if (w == 1)
            one++;
        else 
            two++;
    }
    int ans = 0;
    if (one >= two)
        ans = zero + two + (one - two) / 3;
    else
        ans = zero + one + (two - one) / 3;
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