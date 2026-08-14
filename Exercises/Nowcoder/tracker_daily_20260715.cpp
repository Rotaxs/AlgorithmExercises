#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 5e3 + 10;
int a[N];

void solve()
{
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int diff = n - k;
    ll ans = 0;
    for(int l = 1, r = l + diff - 1; r <= n; l++, r++)
        ans = max(1ll * a[r] - a[l - 1], ans);
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    // cin >> _;
    while (_--) solve();
    
    return 0;
}