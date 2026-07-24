#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 5010;

// bool dp[N][N];

// void solve()
// {
//     int n, m; cin >> n >> m;
//     vector<int> a(m + 1);
//     for (int i = 1; i <= m; i++) cin >> a[i];
//     dp[1][(0 + a[1]) % n] = true;
//     dp[1][((0 - a[1]) % n + n) % n] = true;
//     for (int i = 2; i <= m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (dp[i - 1][j]) {
//                 dp[i][(j + a[i]) % n] = true;
//                 dp[i][((j - a[i]) % n + n) % n] = true;
//             }
//         }
//     }
//     cout << (dp[m][0] ? "YES" : "NO") << endl;
// }

// void solve()
// {
//     int n, m; cin >> n >> m;
//     int s = 0;
//     bitset<5000> f = 1;
//     for (int i = 1; i <= m; i++) {
//         int a; cin >> a;
//         a %= n; s = (s + a) % n;
//         f |= (f << a) | (f >> (n - a));
//     }
//     bool ok = false;
//     for (int A = 0; A < n; A++) {
//         if (f[A] && (2 * A - s) % n == 0) {
//             ok = true;
//             break;
//         }
//     }
//     cout << (ok ? "YES\n" : "NO\n");
// }

// void solve()
// {
//     int n, m; cin >> n >> m;
//     int s = 0;
//     bitset<5000> f = 1;
//     for (int i = 1; i <= m; i++) {
//         int a; cin >> a;
//         a %= n; s = (s + a) % n;
//         f |= (f << a) | (f >> (n - a));
//     }
//     bool ok = false;
//     if ((s & 1) == 0) {
//         if (f[(s + n) >> 1] || f[s >> 1]) ok = true;
//     } else if ((n & 1) == 1) {
//         if (f[(s + n) >> 1]) ok = true;
//     }
//     cout << (ok ? "YES\n" : "NO\n");
// }

void solve()
{
    int n, m; cin >> n >> m;
    int s = 0;
    bitset<5000> f = 1;
    for (int i = 1; i <= m; i++) {
        int a; cin >> a;
        s = (s + a) % n; a = (a << 1) % n;
        f |= (f << a) | (f >> (n - a));
    }
    cout << (f[s % n] ? "YES\n" : "NO\n");
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
