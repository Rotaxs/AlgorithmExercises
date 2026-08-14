#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

// const int inf = 0x3f3f3f3f;
// const ll inf  = 2e18;

bool check(int c, string& x1, string& y1, string& x2, string& y2) {
    int v1 = stoll(x1) * stoll(y1), v2 = stoll(x2) * stoll(y2);
    string res1 = to_string(v1), res2 = to_string(v2);
    cout << res1 << ' ' << res2 << endl;
    for(int i = 0; i < c; i++) {
        if(res1[i] != res2[i]) return true;
    }
    return false;
}

void solve()
{
    int a, b, c; cin >> a >> b >> c;
    string x1, y1, x2, y2;
    if (a >= b) {
        x1 = "1" + string(a - 1, '9') + "0";
        x2 = "1" + string(a - 1, '9') + "9";
        y1 = "1" + string(b - 1, '0') + "0";
        y2 = "1" + string(b - 1, '0') + "9";
    } else {
        x1 = "1" + string(a - 1, '0') + "0";
        x2 = "1" + string(a - 1, '0') + "9";
        y1 = "1" + string(b - 1, '9') + "0";
        y2 = "1" + string(b - 1, '9') + "9";
    }

    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    // cout << check(c, x1, y1, x2, y2) << endl;
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