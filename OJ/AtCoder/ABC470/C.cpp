#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n, q; cin >> n >> q;
    vector<int> a(n + 1, 0), b;
    vector<bool> valid(n + 1, false);
    int ans = 0;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            ans ^= a[x];
            ++a[x];
            ans ^= a[x];
            if (!valid[x]) {
                b.push_back(x);
                valid[x] = true;
            }
        } else if (op == 2) {
            vector<int> ne;
            for (int x : b) {
                ans ^= a[x];
                --a[x];
                ans ^= a[x];
                if (a[x] > 0) {
                    ne.push_back(x);
                } else {
                    valid[x] = false;
                }
            }
            b = ne;
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