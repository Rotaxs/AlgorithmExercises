#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

// const int inf = 0x3f3f3f3f;
// const ll inf  = 2e18;


int dfs(int n, int i, int sum, int cnt) {
    if (i > n * 2) {
        return 1;
    }
    ll ans = 0;
    if (cnt < n) {
        ans += dfs(n, i + 1, sum + 1, cnt + 1);
    }
    if (sum > 0) {
        ans += dfs(n, i + 1, sum - 1, cnt);
    }
    return ans;
}

void solve()
{
    int n; cin >> n;
    ll ans = dfs(n, 1, 0, 0);
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