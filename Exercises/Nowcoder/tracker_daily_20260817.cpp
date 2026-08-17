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
    vector<int> a(n);
    int diff = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) ++diff;
        if (diff >= 2) {
            cout << "Lie" << endl;
            return;
        }
    }
    if (diff == 0) {
        if (a[0] == n - 1 || a[0] <= n / 2) cout << "Other" << endl;
        else cout << "Lie" << endl;
    } else {
        if (a[0] - a[n - 1] == 1) {
            int cnt = 0;
            for (int i = n - 1; i >= 0; --i) {
                if (a[i] == a[n - 1]) ++cnt;
                else break;
            }
            cout << (a[0] == cnt ? "Other" : "Lie") << endl;
        } else {
            cout << "Lie" << endl;
        }
    }
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