#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1010;

void solve()
{
    int n; cin >> n;
    int minn = 1e9, maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        minn = min(minn, a);
        maxn = max(maxn, a);
    }
    int x = ((minn + maxn) >> 1);
    int ans = max(abs(x - minn), abs(x - maxn));
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