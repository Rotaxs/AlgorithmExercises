#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

struct Node { ll x, y; };

void solve()
{
    ll n; cin >> n;
    vector<Node> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
    for (int i = 2; i <= n - 1; i++) {
        ll ax = p[i].x - p[i - 1].x, ay = p[i].y - p[i - 1].y;
        ll bx = p[i + 1].x - p[i].x, by = p[i + 1].y - p[i].y;
        ll c = ax * by - ay * bx;
        if (c > 0) {
            cout << "LEFT ";
        } else if (c < 0) {
            cout << "RIGHT ";
        } else {
            cout << "STRAIGHT ";
        }
    }
    cout << endl;
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