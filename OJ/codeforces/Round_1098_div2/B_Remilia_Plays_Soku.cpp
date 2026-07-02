#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{   
    ll n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    if (n <= 3) { cout << 1 << '\n'; return; }
    cout << min(abs(x1 - x2), n - abs(x1 - x2)) + k << '\n';
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