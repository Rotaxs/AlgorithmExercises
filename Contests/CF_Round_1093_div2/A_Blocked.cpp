#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) { cout << a[1] << '\n'; return; }
    sort(a.begin() + 1, a.end(), greater<int>());
    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i] == a[i + 1]) { cout << -1 << '\n'; return; }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
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