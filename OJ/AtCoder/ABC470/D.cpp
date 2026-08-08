#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n, q; cin >> n >> q;
    vector<int> p(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    bool swapPos = true;

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y;
            if (swapPos) {
                swap(p[x], p[y]);
                swap(pos[p[x]], pos[p[y]]);
            } else {
                swap(p[pos[x]], p[pos[y]]);
                swap(pos[x], pos[y]);
            }
        } else if (op == 2) {
            swapPos = !swapPos;
        }
    }

    if (swapPos) {
        for (int i = 1; i <= n; ++i) {
            cout << p[i] << ' ';
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            cout << pos[i] << ' ';
        }
    }
    
    cout << endl;
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