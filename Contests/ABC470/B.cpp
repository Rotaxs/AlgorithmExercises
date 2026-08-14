#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

int cnt[110];

void solve()
{
    int n; cin >> n;
    int maxn = 0;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        ++cnt[a];
        maxn = max(maxn, a);
    }
    int maxCnt = 0;
    for (int i = 1; i <= maxn; ++i) {
        maxCnt = max(maxCnt, cnt[i]);
    }
    cout << n - maxCnt << endl;
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