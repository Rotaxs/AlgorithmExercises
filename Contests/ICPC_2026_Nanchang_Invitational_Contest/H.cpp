#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, k; cin >> n >> k;
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        s ^= x;

    }

    if (s != 0 && (s & -s) <= k) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

// void solve() {
//     ll n, k; cin >> n >> k;
//     vector<ll> a(n + 1);
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//     }

//     for (int p = 0; p <= 32; ++p) {
//         if ((1ll << p) > k) break;
//         ll cnt = 0;
//         for (int i = 1; i <= n; ++i) {
//             cnt += (a[i] >> p);
//         }
//         if (cnt & 1) {
//             cout << "Alice" << endl;
//             return;
//         }
//     }
    
//     cout << "Bob" << endl;
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}

