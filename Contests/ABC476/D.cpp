#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll x, y;
    cin >> x >> y;
    vector<ll> A(n + 1), B(m + 1);
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    for (int j = 1; j <= m; ++j)
        cin >> B[j];

    sort(A.begin() + 1, A.end());
    sort(B.begin() + 1, B.end());

    vector<ll> preA(n + 1), preB(m + 1);

    for (int i = 1; i <= n; ++i) {
        preA[i] = preA[i - 1] + A[i];
    }
    for (int j = 1; j <= m; ++j) {
        preB[j] = preB[j - 1] + B[j];
    }

    ll cost_y = 0;
    int ans = 0;

    for (int cnt_B = 0; cnt_B <= m; ++cnt_B) {
        cost_y += (B[cnt_B] + k - 1) / k;
        if (cost_y > y) {
            break;
        }
        ll rem_y = y - cost_y;
        ll rem_x = x + (cost_y * k - preB[cnt_B]);
        int l = 0, r = n + 1;
        while ((l + 1) != r) {
            int mid = (l + r) >> 1;
            ll cost_A = preA[mid];
            if (cost_A <= rem_x + rem_y * k)
                l = mid;
            else
                r = mid;
        }
        int cnt_A = l;
        ans = max(ans, cnt_A + cnt_B);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}
