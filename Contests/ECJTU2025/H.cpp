#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    ll sum = 0, cnt = 0;
    for (int i = (n - 1) / 2; i < n;) {
        int j = i;
        while (j < n && a[j] == a[i]) ++j;
        cnt += j - i;
        if (j >= n) break;
        ll s = (a[j] - a[i]) * cnt;
        if (k + 1 <= sum + s) {
            cout << a[i] + (k - sum) / cnt << endl;
            return;
        }
        sum += s;
        i = j;
    }

    cout << a.back() + (k - sum) / cnt << endl;
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
