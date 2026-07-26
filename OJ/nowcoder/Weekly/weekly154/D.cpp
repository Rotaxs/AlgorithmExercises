#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int cnt = 0;
    vector<int> diff(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] != s[(i + 1) % n]) {
            diff[i] = 1;
            cnt++;
        }
    }
    while (q--) {
        int l, r; cin >> l >> r;
        l = (l - 1 + n) % n;
        if (l != r) {
            if (diff[l] == 1) cnt--;
            else cnt++;
            diff[l] ^= 1;

            if (diff[r] == 1) cnt--;
            else cnt++;
            diff[r] ^= 1;
        }
        cout << cnt << endl;
    }
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