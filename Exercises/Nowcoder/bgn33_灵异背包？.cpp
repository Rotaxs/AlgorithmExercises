#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    vector<int> a;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int num; cin >> num;
        if ((num & 1) == 0) ans += num;
        else a.push_back(num);
    }
    sort(a.begin(), a.end());
    int len = a.size();
    for (int i = 0; i < len; i++) ans += a[i];
    if ((len & 1))
        ans -= a[0];
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    
    return 0;
}