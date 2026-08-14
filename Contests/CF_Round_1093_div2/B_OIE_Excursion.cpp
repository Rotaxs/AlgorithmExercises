#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    int cnt = 0, maxcnt = 0;
    int pre = -1, cur = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> cur;
        if (cur == pre) cnt++;
        else maxcnt = max(cnt, maxcnt), cnt = 1;
        pre = cur;
    }
    maxcnt = max(maxcnt, cnt);
    if (maxcnt >= m) cout << "NO\n";
    else cout << "YES\n";

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