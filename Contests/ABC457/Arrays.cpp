#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<vector<int>> a(1);
    for (int i = 1; i <= n; i++)
    {
        int l; cin >> l;
        vector<int> b(l + 1);
        for (int j = 1; j <= l; j++) cin >> b[j];
        a.push_back(b);
    }
    int x, y; cin >> x >> y;
    cout << a[x][y] << '\n';
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