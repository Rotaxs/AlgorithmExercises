#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

bool check(const vector<int> &a, double x) {
    double sum = 0;
    for (int i = 0; i < a.size(); ++i) {
        sum += x;
            if (a[i] != (int)sum) return false;
    }
    return true;
}

void solve()
{
    int n; cin >> n;
    double ans = 2e9;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        ans = min(ans, (double)(a + 1) / i);
    }
    cout << fixed << setprecision(4);
    cout << ans << endl;
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