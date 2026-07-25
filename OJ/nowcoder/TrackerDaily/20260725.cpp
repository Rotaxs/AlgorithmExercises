#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = LONG_LONG_MAX;

// void solve()
// {
//     ll n, m; cin >> n >> m;
//     ll sumh = 0, minc = inf, maxh = 0, maxm = 0;
//     vector<ll> h(n + 1), c(n + 1);
//     for (int i = 1; i <= n; i++) {
//         cin >> h[i] >> c[i];
//         maxm += h[i] - c[i];
//         sumh += h[i];
//         minc = min(minc, c[i]);
//         maxh = max(maxh, h[i]);
//     }
//     m = min(m, maxm);
//     auto check = [&](ll H) {
//         ll sumx = 0;
//         for (int i = 1; i <= n; i++) {
//             if (h[i] >= H)
//                 sumx += h[i] - max(H, c[i]);
//             if (sumx > m) return false;
//         }
//         return sumx <= m;
//     };
//     ll L = minc - 1, R = maxh + 1;
//     while ((L + 1) != R) {
//         ll M = L + ((R - L) >> 1);
//         if (check(M)) R = M;
//         else L = M;
//     }
//     ll ans = 0, cut = 0;
//     for (int i = 1; i <= n; i++) {
//         if (h[i] >= R) {
//             ll x = h[i] - max(R, c[i]);
//             cut += x;
//             ans += x * (2 * h[i] - x);
//         }
//     }
//     ll rem = m - cut;
//     if (rem > 0)
//         ans += rem * (2 * R - 1);
//     cout << ans << endl;
// }

// void solve()
// {
//     ll n, m; cin >> n >> m;
//     ll sumh = 0, minc = inf, maxh = 0;
//     vector<ll> h(n + 1), c(n + 1);
//     for (int i = 1; i <= n; i++) {
//         cin >> h[i] >> c[i];
//         sumh += h[i];
//         minc = min(minc, c[i]);
//         maxh = max(maxh, h[i]);
//     }
//     auto check = [&](ll H) {
//         ll sumx = 0;
//         for (int i = 1; i <= n; i++) {
//             if (h[i] >= H)
//                 sumx += h[i] - max(H, c[i]);
//             if (sumx > m) return false;
//         }
//         return sumx <= m;
//     };
//     ll L = minc - 1, R = maxh + 1;
//     while ((L + 1) != R) {
//         ll M = L + ((R - L) >> 1);
//         if (check(M)) R = M;
//         else L = M;
//     }
//     ll ans = 0, cut = 0;
//     for (int i = 1; i <= n; i++) {
//         if (h[i] >= R) {
//             ll x = h[i] - max(R, c[i]);
//             cut += x;
//             ans += x * (2 * h[i] - x);
//             h[i] -= x;
//         }
//     }
//     ll rem = m - cut;
//     for (int i = 1; i <= n && rem > 0; i++) {
//         if (h[i] > c[i] && h[i] == R) {
//             ans += 2 * R - 1;
//             rem--;
//         }
//     }
//     cout << ans << endl;
// }

void solve()
{
    ll n, m; cin >> n >> m;
    vector<int> h(n + 1), c(n + 1);
    int minc = inf, maxh = 0;
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> c[i];
        minc = min(c[i], minc);
        maxh = max(h[i], maxh);
    }
    vector<ll> cnt(maxh + 1, 0);
    for (int i = 1; i <= n; i++) {
        cnt[c[i] + 1]++;
        cnt[h[i] + 1]--;
    }
    for (int i = 1; i <= maxh; i++)
        cnt[i] += cnt[i - 1];

    ll ans = 0;
    for (int i = maxh; i >= minc + 1; i--) {
        if (cnt[i] > 0) {
            ll val = 2 * i - 1;
            if (cnt[i] <= m) {
                m -= cnt[i];
                ans += cnt[i] * val;
            } else {
                ans += m * val;
                break;
            }
        }
    }
    cout << ans << endl;
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