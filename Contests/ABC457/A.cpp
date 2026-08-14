#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int x; cin >> x;
    cout << a[x];
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