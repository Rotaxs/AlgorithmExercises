#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct Enemy {
    ll a, b;

    bool operator<(const Enemy& other) const {
        return a < other.a;
    }
};

void solve() {
    ll n, k, s;
    cin >> n >> k >> s;
    vector<Enemy> e(n);
    for (int i = 0; i < n; ++i) {
        cin >> e[i].a >> e[i].b;
    }

    sort(e.begin(), e.end());

    while (s < e[0].a && k > 0) {
        s <<= 1;
        --k;
    }

    for (int i = 0; i < n; ++i) {
        if (s < e[i].a) break;
        s += e[i].b;
        if (i + 1 < n) {
            while (s < e[i + 1].a && k > 0) {
                s <<= 1;
                --k;
            }
        }
    }

    while (k > 0) {
        s <<= 1;
        --k;
    }

    cout << s << endl;
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
