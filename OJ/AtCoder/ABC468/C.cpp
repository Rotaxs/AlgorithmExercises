#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

ll fac(int n)
{
    ll ret = 1;
    for (int i = 1; i <= n; i++)
        ret *= i;
    return ret;
}

void solve()
{
    int n; cin >> n;
    vector<int> F(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++) { 
        F[i] = fac(i);
    };
    int l = 0;
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        int cnt = 0;
        vis[p] = true;
        for (int j = 1; j < p; j++) {
            if (!vis[j]) cnt++;
        }
        l += cnt * F[n - i];
    }
    fill(vis.begin(), vis.end(), false);
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        int cnt = 0;
        vis[p] = true;
        for (int j = p + 1; j <= n; j++) {
            if (!vis[j]) cnt++;
        }
        l += cnt * F[n - i];
    }
    cout << ((F[n] - l - 2) >= 0 ? F[n] - l - 2 : 0) << endl;
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