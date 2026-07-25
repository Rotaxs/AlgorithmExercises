#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    string s; cin >> s;
    int len = s.size();
    int ans = 0;
    for (int i = 0; i < len; i++) {
        int L = i, R = i;
        bool used = false;
        while (s[L] == s[R] | !used) {
            if (s[L] != s[R]) used = true;
            L--; R++;
            ans++;
            if (L < 0 || R >= len) break;
        }
    }
    for (int i = 0; i < len - 1; i++) {
        int L = i, R = i + 1;
        bool used = false;
        while (s[L] == s[R] | !used) {
            if (s[L] != s[R]) used = true;
            L--; R++;
            ans++;
            if (L < 0 || R >= len) break;
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