#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int diff = (x - a[k] + n) % n;
    for (int &e : a) 
        cout << (e + diff) % n << ' ';
    cout << endl;

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