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

void solve()
{
	int n; cin >> n;
    int odd = 0, mx = 0;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        mx = max(mx, a);
        if (a & 1) ++odd;
    }
    if (odd & 1) cout << (mx + 1) / 2 << endl;
    else cout << mx / 2 << endl;
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