#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
    int ans = 0;
    if ((a1 > b1 && a2 >= b2) || (a1 == b1 && a2 > b2)) ans += 2;
    if ((a1 > b2 && a2 >= b1) || (a1 == b2 && a2 > b1)) ans += 2;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}