#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int a; cin >> a;
    if (a == 1) {
        cout << 2 << ' ' << (a ^ 2) << endl;
        return;
    }
    if (a == 1e9) {
        cout << 512 << ' ' << (a ^ 512) << endl;
        return;
    }
    cout << 1 << ' ' << (a ^ 1) << endl;
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
