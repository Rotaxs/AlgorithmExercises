#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;

void solve()
{
    int n, k; cin >> n >> k;
    vector<vector<int>> a(1);
    vector<int> l(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i];
        vector<int> aa(l[i] + 1);
        for (int j = 1; j <= l[i]; j++)
        {
            cin >> aa[j];
        }
        a.push_back(aa);
    };

    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        int c; cin >> c;
        cur += c * l[i];
        if (cur >= k)
        {
            cur -= c * l[i];
            int d = k - cur;
            if (d % l[i] != 0)
                cout << a[i][d % l[i]] << '\n'; 
            else 
                cout << a[i][a[i].size() - 1] << '\n';
            return;
        }
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();
    
    return 0;
}