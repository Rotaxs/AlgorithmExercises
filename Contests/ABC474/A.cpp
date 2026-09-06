#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int x; cin >> x;
    if (x == 2) {
        cout << 1 << endl;
        return;
    }
    cout << (x + 1) % 3 << endl;
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
