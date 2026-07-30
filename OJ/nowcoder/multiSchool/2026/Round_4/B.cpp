#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    ll p; cin >> p;
    if (p == 2) {
        cout << "12 1 71\n";
        return;
    }
    if (p == 3) {
        cout << "4 1 13\n";
        return;
    }
    ll x = sqrt(p); 
    while (x * x - x <= p) {
        x++;
    }
    
    ll q = x * x - p;
    cout << x << ' ' << x << ' ' << q << endl;
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