#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

bool ask(int u, int v, int d) {
    cout << "? " << u << ' ' << v << ' ' << d << endl;
    fflush(stdout);
    int status; cin >> status;
    if (status == -1) exit(0);
    return status;
}

void solve()
{
    int n; cin >> n;

    int len = 0;
    
    auto find = [&](int u) -> int {
        int res = 1;
        for (int v = 1; v <= n; ++v) {
            if (u == v) continue;
            if (ask(u, v, len + 1)) {
                res = v;
                ++len;

                while (ask(u, v, len + 1)) {
                    ++len;
                }
            }
        }
        return res;
    };

    int A = find(1);
    int B = find(A);

    cout << "! " << A << ' ' << B << ' ' << len << endl;
    fflush(stdout);
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    
    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}
