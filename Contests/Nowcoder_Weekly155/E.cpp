#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int k, q; cin >> k >> q;
    while (q--) {
        ull l, r, h, z; cin >> l >> r >> h >> z;
        ull Z = 0;
        for (ull i = 0; i < h; ++i) {
            if ((z >> i) & 1) {
                Z |= (1ULL << (h - 1 - i));
            }
        }
        ull P = Z;
        for (ull i = 1; i < h; i <<= 1) {
            P ^= (P >> i);
        }
        ull L = P << (k - h);
        ull R = ((P + 1) << (k - h)) - 1;
        ull start = max(l - 1, L), end = min(r - 1, R);
        if (start <= end) {
            cout << end - start + 1 << endl;
        } else {
            cout << 0 << endl;
        }

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