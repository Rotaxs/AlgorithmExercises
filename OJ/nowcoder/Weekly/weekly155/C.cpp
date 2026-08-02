#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
string ss = "ABCDE";

int getPos(char ch) {
    int pos = 0;
    switch (ch) {
    case 'A': pos = 0; break;
    case 'B': pos = 1; break;
    case 'C': pos = 2; break;
    case 'D': pos = 3; break;
    case 'E': pos = 4; break;
    }
    return pos;
}

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    string t; cin >> t;
    int ans = inf;
    for (int c = 0; c < n; ++c) {
        for (int p = 0; p <= 4; ++p) {
            for (int q = 0; q <= 4; ++q) {
                int cnt = 0;
                for (int i = 0; i < c; ++i) {
                    if (ss[(getPos(s[i]) + p) % 5] != t[i]) cnt++;
                }
                for (int i = c; i < n; ++i) {
                    if (ss[(getPos(s[i]) + q) % 5] != t[i]) cnt++;
                }
                ans = min(ans, cnt);
            }
        }
    }
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