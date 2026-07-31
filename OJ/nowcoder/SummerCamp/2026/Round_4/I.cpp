#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    string s; cin >> s;
    int k; cin >> k;
    int len = s.size();
    int window = 7 + k;
    if (len < window) {
        cout << 0 << endl;
        return;
    }
    string t = "Rounddo";
    for (int i = 0; i < k; ++k) t += "g";
    s = s + s;
    
    for (int l = 0, r = window; r <= 2 * len; l++, r++) {

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