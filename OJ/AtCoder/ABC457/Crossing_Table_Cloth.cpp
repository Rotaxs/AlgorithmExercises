#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
const int M = 2e5 + 10;

int l[M], r[M];

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> ll(n + 1), rr(n + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i];
        ll[l[i]].push_back(i);
        rr[r[i]].push_back(i);
    }
    int q; cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int s, t; cin >> s >> t;
        if (ll[s].empty() || rr[t].empty())
        {
            cout << "No\n"; 
            continue;
        }
        if (ll[s] != rr[t])
        {
            cout << "Yes\n";
            continue;
        }
        else
        {
            for (int j = s; j <= t; j++)
            {
                if (ll[j])
            }
        }

    }
    
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