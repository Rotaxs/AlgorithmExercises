#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int pivot = a[(n + 1) / 2];
    int ans = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        int x = a[i], y = a[n + 1 - i];
        if (x == pivot && y == pivot)
            break;
        ans++;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while (t--) solve();
    
    return 0;
}