#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 3e5 + 10;

int cnt[35][2][2], st[35][2];

inline int get(int v, int i) { return (v >> i) & 1; }

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        for (int i = 0; i <= 30; i++) {
            cnt[i][get(a, i)][get(a, i + 1)]++;
        }
    }
    for (int i = 0; i <= 31; i++) {
        st[i][0] = 0;
        st[i][1] = 1;
    }
    int m; cin >> m;
    while (m--) {
        int t, x; cin >> t >> x;
        for (int i = 0; i <= 30; i++) {
            int v = get(x, i);
            if (t == 1) {
                st[i][0] &= v;
                st[i][1] &= v;
            } else if (t == 2) {
                st[i][0] |= v;
                st[i][1] |= v;
            } else {
                st[i][0] ^= v;
                st[i][1] ^= v;
            }
        }
        int ans = 0;
        for (int i = 0; i <= 30; i++) {
            for (int a = 0; a <= 1; a++) {
                for (int b = 0; b <= 1; b++){
                    if (st[i][a] == 1 && st[i + 1][b] == 0)
                        ans += cnt[i][a][b];
                }
            }
        }
        cout << ans << endl;
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