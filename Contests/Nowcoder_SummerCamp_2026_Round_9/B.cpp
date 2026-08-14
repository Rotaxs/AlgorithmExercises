#include <bits/stdc++.h>
#define endl '\n'
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x)  << " (Line " << __LINE__ << ")" << endl
#else
#define debug(x)
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 10;

int cntX[N], cntY[N];

void solve()
{
	int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y; cin >> x >> y;
        cntX[x]++, cntY[y]++;
    }
    int maxCntX = 0, maxCntY = 0;
    for (int i = 1; i <= n; ++i) {
        maxCntX = max(maxCntX, cntX[i]);
        maxCntY = max(maxCntY, cntY[i]);
    }
    cout << n - max(maxCntX, maxCntY) << endl;
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