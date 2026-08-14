#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

// const int inf = 0x3f3f3f3f;
// const ll inf  = 2e18;

void solve()
{
    int n; cin >> n;
    bool odd = false;
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        mx = max(mx, a);
        if (a & 1) odd = true;
    }
    if (odd) {
        if ((mx - n) & 1) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    } else {
        if (((mx >> 1) - n) & 1) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
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