#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1), q(n + 1), id(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        id[p[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> q[i];
    }

    ll L = 0, R = inf;
    for (int i = 1; i <= n - 1; ++i) {
        int q1 = q[i], q2 = q[i + 1];
        if (id[q1] < id[q2]) {
            if (q1 > q2) {
                R = min(R, 1ll * (id[q2] - id[q1]) / (q1 - q2));
            }
        } else if (id[q1] > id[q2]) {
            ll idDiff = id[q1] - id[q2];
            if (q2 > q1) {
                ll qDiff = q2 - q1;
                L = max(L, idDiff / qDiff + 1);
            } else {
                cout << 0 << endl;
                return;
            }
        }
    }

    if (R == inf) {
        cout << "inf" << endl;
    } else {
        cout << (L > R ? 0 : R - L + 1) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}
